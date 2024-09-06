#include "vehicle_factory.hpp"
#include "vehicle.hpp"
Vehicle *VehicleFactory::getVehicle(string vehicleType)
{
    Vehicle *vechicle = nullptr;
    if (vehicleType == "car")
    {
        vechicle = new Car();
    }
    else if (vehicleType == "bike")
    {
        vechicle = new Bike();
    }

    return vechicle;
}