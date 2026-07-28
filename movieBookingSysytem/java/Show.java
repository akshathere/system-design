package movieBookingSysytem.java;
import java.util.Date;

public class Show {
    int id;
    Screen screen;
    Movie movie;
    Date startTime;
    int duration;
    Show(int id, Screen screen, Movie movie, Date   startTime, int duration) {
        this.id = id;
        this.screen = screen;
        this.movie = movie;
        this.startTime = startTime;
        this.duration = duration;
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public Screen getScreen() {
        return screen;
    }
    public void setScreen(Screen screen) {
        this.screen = screen;
    }
    public Movie getMovie() {
        return movie;
    }
    public void setMovie(Movie movie) {
        this.movie = movie;
    }
    public Date getStartTime() {
        return startTime;
    }
    public void setStartTime(Date startTime) {
        this.startTime = startTime;
    }
    public int getDuration() {
        return duration;
    }
    public void setDuration(int duration) {
        this.duration = duration;
    }
}
