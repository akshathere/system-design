package movieBookingSysytem.java;
import java.util.ArrayList;
import java.util.List;
public class Theator {
    int id;
    String name;
    List<Screen> screens;
    Theator(int id, String name) {
        this.id = id;
        this.name = name;
        this.screens = new ArrayList<>();
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public List<Screen> getScreens() {
        return screens;
    }
}
