package movieBookingSysytem.java;

public class Seat {
    int id;
    int row;
    SeatCategory category;
    Seat(int id,int row,SeatCategory category){
        this.id= id;
        this.row=row;
        this.category=category;
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public int getRow() {
        return row;
    }
    public void setRow(int row) {
        this.row = row;
    }
    public SeatCategory getCategory() {
        return category;
    }
    public void setCategory(SeatCategory category) {
        this.category = category;
    }
    
}
