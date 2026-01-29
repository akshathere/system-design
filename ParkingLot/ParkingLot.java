package ParkingLot;

import java.util.ArrayList;
import  java.util.List;
import java.lang.RuntimeException;
public class ParkingLot {
    List<Level> levels = new ArrayList<>();
    void addLevel(Level level){
        System.out.println("Adding level: " + level.getFloorNumber() + " to parking lot");
        levels.add(level);
    }
    public void freeSpot(ParkingSpot spot){
        spot.removeVehicle();
    }

    public ParkingSpot getAvailableSpot(Vehicle vehicle){
        ParkingSpot spot = null;
        for(Level level : levels){
            System.out.println("Checking level: " + level.getFloorNumber() + " for available spot for vehicle type: " + vehicle.vehicleType);
            spot = level.getAvailableSpot(vehicle);
        }
        if(spot == null){
            throw new  RuntimeException("No Spot Available");
        }
        return spot; 
    }

    public void unparkVehicle(Ticket ticket){
        ParkingSpot spot = ticket.getParkingSpot();
        spot.removeVehicle();
    }
    public Ticket  parkVehicle(Vehicle vehicle){
        ParkingSpot spot = getAvailableSpot(vehicle);
            spot.parkVehicle(vehicle);
            return new Ticket(vehicle, spot);
    }

}
