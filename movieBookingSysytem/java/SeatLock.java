package movieBookingSysytem.java;
import java.time.Instant;
import java.util.Date;
public class SeatLock {
    Seat seat;
    User lockedBy;
    Date lockTime;
    int timeout;
    Show show;
    SeatLock(Seat seat, User lockedBy, Date lockTime, int timeout, Show show) {
        this.seat = seat;
        this.lockedBy = lockedBy;
        this.lockTime = lockTime;
        this.timeout = timeout;
        this.show = show;
    }
    public boolean isLockExpired() {
        final Instant currentInstant = new Date().toInstant();
        final Instant lockInstant = lockTime.toInstant().plusSeconds(timeout);
        return currentInstant.isAfter(lockInstant);
    }
    public Seat getSeat() {
        return seat;
    }
    public void setSeat(Seat seat) {
        this.seat = seat;
    }
    public User getLockedBy() {
        return lockedBy;
    }
    public void setLockedBy(User lockedBy) {
        this.lockedBy = lockedBy;
    }
    public Date getLockTime() {
        return lockTime;
    }
    public void setLockTime(Date lockTime) {
        this.lockTime = lockTime;
    }
    public int getTimeout() {
        return timeout;
    }
    public void setTimeout(int timeout) {
        this.timeout = timeout;
    }
    public Show getShow() {
        return show;
    }
    public void setShow(Show show) {
        this.show = show;
    }

}
