package ParkingLot;

public class Driver {
    public static void main(String[] args) {
        ParkingLot parkingLot = new ParkingLot();
        Level level1 = new Level(1);
        level1.addParkingSpot(new ParkingSpot(SpotType.CAR,1));
        level1.addParkingSpot(new ParkingSpot(SpotType.BIKE,2));
        level1.addParkingSpot(new ParkingSpot(SpotType.TRUCK,3));

        parkingLot.addLevel(level1);

        Vehicle bike = new Bike("UP70 BuBu Ki Bike");
        Vehicle car = new Car("UP70 BuBu Ki Car");
        Vehicle truct = new Truck("UP70 BuBu Ka Truck");

        // ab park krte vehicle
        // but uske liye hme chaiyeeeee tickettt yeeee
        Ticket ticket = parkingLot.parkVehicle(bike);
        System.out.println("Bike parked at spot: " + ticket.getParkingSpot().getId());
    }
}
