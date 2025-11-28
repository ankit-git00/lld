#ifndef PARKING_LOT_HPP
#define PARKING_LOT_HPP
#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>

#include "parking_spot.hpp"

class ParkingLot
{

private:
    int capacity;
    vector<ParkingSpot *> spots;
    map<string, ParkingSpot *> occupiedSpots;
    int availableSpots;

public:
    ParkingLot(int numCompact, int numRegular, int numLarge);

    int getCapacity() const;
    int getAvailableSpots() const;
    bool parkVehicle(Vehicle *Vehicle);
    Vehicle *unParkVehicle(string licensePlate);
    Vehicle *findVehicle(string licensePlate) const;
    void displayInfo() const;

private:
    ParkingSpot *
    findAvailableSpot(Vehicle *vehicle) const;
};

#endif