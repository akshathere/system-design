package movieBookingSysytem.java;
import java.util.*;
public interface ISeatLockProvider {
    // simply lock all the seats for this user for this show 
    void lockSeats(Show show,List<Seat> seats,User user) throws Exception;
    // here unlock the seats for this user for this show, and before that do validation 
    // that the seats are locked by this user for this show
    void unlockSeats(Show show,List<Seat> seats,User user);
    // this is the validation method to check if the seats are locked by this user for this show and 
    // also check if the lock is expired or not
    boolean validateLock(Show show,Seat seat,User user);
    List<Seat> getLockedSeats(Show show);

}
