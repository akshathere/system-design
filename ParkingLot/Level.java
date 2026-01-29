package ParkingLot;

import java.util.List;

public class Level {
    int floorNumber;
    List<ParkingSpot> parkingSpots;

    Level(int floorNumber) {
        this.floorNumber = floorNumber;
        parkingSpots = new java.util.ArrayList<>();
    }

    public int getFloorNumber() {
        return floorNumber;
    }
    public void setFloorNumber(int floorNumber) {
        this.floorNumber = floorNumber;
    }
    public List<ParkingSpot> getParkingSpots() {
        return parkingSpots;
    }
    public void setParkingSpots(List<ParkingSpot> parkingSpots) {
        this.parkingSpots = parkingSpots;
    }

    public ParkingSpot getAvailableSpot(Vehicle vehicle){

        for(ParkingSpot spot : parkingSpots){
            if(spot.canFitVehicle(vehicle)){
                return spot;
            }
        }
        return null;
    }
    public void addParkingSpot(ParkingSpot spot){
        parkingSpots.add(spot);
        System.out.println("Added spot id: " + spot.getId() + " of type: " + spot.spotType + " to level: " + this.floorNumber);
    }

    public void parkVehicle(Vehicle vehicle){
        ParkingSpot spot = getAvailableSpot(vehicle);
        if(spot != null){
            spot.parkVehicle(vehicle);
        }
    }
}
