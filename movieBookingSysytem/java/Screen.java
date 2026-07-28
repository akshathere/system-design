package movieBookingSysytem.java;
import java.util.ArrayList;
import java.util.List;
public class Screen {
    int id;
    Theator theator;
    List<Seat> seats;
    Screen(int id, Theator theator) {
        this.id = id;
        this.theator = theator;
        this.seats = new ArrayList<>();
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public Theator getTheator() {
        return theator;
    }
    public void setTheator(Theator theator) {
        this.theator = theator;
    }
    public List<Seat> getSeats() {
        return seats;
    }
}
