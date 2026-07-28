package movieBookingSysytem.java;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.List;
import java.util.Date;
import java.util.Collections;
import java.util.stream.Collectors;
public class SeatLockProvider implements ISeatLockProvider {
    private final int lockTimeout;
    private final Map<Show,Map<Seat,SeatLock>> locks;
    public SeatLockProvider(int lockTimeout) {
        this.lockTimeout = lockTimeout;
        this.locks = new ConcurrentHashMap<>();
    }
    @Override
    public void lockSeats(final Show show,final List<Seat> seats,final User user) throws Exception{
        // computeIfAbsent is thread safe read from the map 
        Map<Seat,SeatLock> seatLocks = locks.computeIfAbsent(show, k -> new ConcurrentHashMap<>());
        synchronized (seatLocks){
            for (Seat seat : seats) {
                if(seatLocks.containsKey(seat)){
                    SeatLock existing = seatLocks.get(seat);
                    if(!existing.isLockExpired()){
                        throw new Exception("Seat "+ seat.getId()+" is already locked.");
                    }
                }
            }
            Date now = new Date();
            for(Seat seat:seats){
                    SeatLock lock = new SeatLock(seat, user, now, lockTimeout, show);
                    seatLocks.put(seat,lock);
            }
        }
    }

    @Override
    public void unlockSeats(final Show show, final List<Seat> seats,final User user){
        Map<Seat,SeatLock> seatLocks = locks.get(show);
        if(seatLocks==null) return;
        synchronized (seatLocks){
            for(Seat seat : seats){
                SeatLock lock = seatLocks.get(seat);
                if(lock!=null && lock.getLockedBy()==user) {
                    seatLocks.remove(seat);
                }
            }
        }
    }

    @Override
    public boolean validateLock(final Show show,final Seat seat,final User user){
        Map<Seat,SeatLock> seatLocks = locks.get(show);
        if(seatLocks == null) return false;
        synchronized(seatLocks){
            SeatLock lock = seatLocks.get(seat);
            return (lock!=null &&!lock.isLockExpired() && lock.getLockedBy()==user);
        }
    }

    @Override 
    public List<Seat> getLockedSeats(final Show show){
        Map<Seat,SeatLock> seatLocks = locks.get(show);
        if(seatLocks==null) return Collections.emptyList();
        synchronized (seatLocks){
            return seatLocks.entrySet().stream()
                    .filter(entry -> !entry.getValue().isLockExpired())
                    .map(Map.Entry::getKey)
                    .collect(Collectors.toList());
        }
    }
}
