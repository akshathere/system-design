package ParkingLot;

public class ParkingSpot {
    SpotType spotType;
    int spotId;
    boolean isOccupied; 
    Vehicle currentVehicle;

    public ParkingSpot(SpotType spotType, int spotId) {
        this.spotType = spotType;
        this.spotId = spotId;
        this.isOccupied = false;
        this.currentVehicle = null;
    }
    public int getId() {
        return spotId;
    }
    public void setId(int spotId) {
        this.spotId = spotId;
    }
 /// check kr rhe if vehicle can fit in the spot
    public boolean canFitVehicle(Vehicle vehicle) {
        if(spotType.name().equalsIgnoreCase(vehicle.vehicleType.name()) && !isOccupied) {
            return true;
        }
        return false;
    }
/// ab fit krenge
/// park kr rhe
    public boolean parkVehicle(Vehicle vehicle) {
        if(canFitVehicle(vehicle)) {
            this.currentVehicle = vehicle;
            this.isOccupied = true;
            return true;
        }
        return false;
    }
// ab nikal rhe
    public boolean removeVehicle() {
        if(isOccupied) {
            this.currentVehicle = null;
            this.isOccupied = false;
            return true;
        }
        return false;
    }
    

}
