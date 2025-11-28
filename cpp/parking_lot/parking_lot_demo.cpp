#include <bits/stdc++.h>
using namespace std;
#include "parking_lot.hpp"

int main()
{
    std::cout << "Start" << std::endl;
    std::cout.flush();
    ParkingLot parkingLot(2, 3, 1);
    parkingLot.displayInfo();

    Vehicle *v1 = new Vehicle("ABC123", VehicleType::CAR, "Red");
    Vehicle *truck1 = new Vehicle("DEF!@#", VehicleType::TRUCK, "Blue");

    if (parkingLot.parkVehicle(truck1))
    {
        std::cout << "Vehicle parked successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to park vehicle." << std::endl;
    }

    parkingLot.displayInfo();

    parkingLot.findVehicle(v1->getLicensePlate())->displayInfo();
    Vehicle *vehicle = parkingLot.unParkVehicle(v1->getLicensePlate());
    delete v1;
    parkingLot.displayInfo();

    std::cout
        << "End" << std::endl;
    return 0;
}
