#ifndef PARKING_SPOT_HPP
#define PARKING_SPOT_HPP

#include "vehicle.hpp"

#include <iostream>
using namespace std;
#include <string.h>

enum class SpotType
{
    COMPACT,
    REGULAR,
    LARGE
};

class ParkingSpot
{
private:
    int spotNumber;
    SpotType type;
    Vehicle *vehicle;
    bool available;

public:
    ParkingSpot(int spotNumber, SpotType type);
    int getSpotNumber() const;
    bool parkVehicle(Vehicle *vehicle);
    SpotType getType() const;
    Vehicle *getParkedVehicle() const;
    Vehicle *removeVehicle();
    bool isAvailable() const;
    bool canFitVehicle(Vehicle *vehicle) const;

    void displayInfo() const;
};

#endif