#ifndef vechicle_factory_hpp
#define vechicle_factory_hpp

#include <iostream>
#include "car.hpp"
#include "bike.hpp"
using namespace std;

class VehicleFactory
{
public:
    static Vehicle *getVehicle(string vehicleType);
};
#endif