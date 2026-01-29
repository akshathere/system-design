package ParkingLot;

import java.time.LocalDateTime;

public class Ticket {
    int ticketId;

    Vehicle vehicle;

    ParkingSpot parkingSpot;

    LocalDateTime entryTime;
    // ye le rhe hm kyunki ye system ki responsibility h
    static int counter = 0;
    // for interviewer that ye integer value km rhegi
    // we can counter by saying we can use 
    // long
    // UUID
    // AtomicLong which is safe for multithreading environment
    Ticket(Vehicle vehicle, ParkingSpot parkingSpot) {
        this.ticketId = ++counter;
        this.vehicle = vehicle;
        this.parkingSpot = parkingSpot;
        this.entryTime = LocalDateTime.now();
    } 
    
    int getTicketId() {
        return ticketId;
    }

    ParkingSpot getParkingSpot() {
        return parkingSpot;
    }
}
