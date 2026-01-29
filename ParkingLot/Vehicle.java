package ParkingLot;

public abstract class Vehicle {
    String licensePlate;
    VehicleType vehicleType;

    public Vehicle(String licensePlate, VehicleType vehicleType) {
        this.licensePlate = licensePlate;
        this.vehicleType = vehicleType;
    }

    public String getLicensePlate() {
        return licensePlate;
    }

    public VehicleType getSize() {
        return vehicleType;
    }
}