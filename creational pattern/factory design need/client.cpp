#include <iostream>
#include "car.hpp"
#include "bike.hpp"
using namespace std;

/*
// problem in this simple design is

we are importing individual file for client
what if client want bus, auto etc.. then he needs to
add them seperatly and compile code again
then create exicuteble client

and what if he is not willing to do it.
There comes the factory design.

int main()
{
    string vehicleType;
    cin >> vehicleType;
-----------------------------------------------------------------
    Vehicle *vechicle;
    if (vehicleType == "car")
    {
        vechicle = new Car();
    }
    else if (vehicleType == "bike")
    {
        vechicle = new Bike();
    }

    vechicle->createVehicle();
}

*/

// we need some design where logic is not expose to client
// client wont be brothered
