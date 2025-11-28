#include "parking_spot.hpp"

ParkingSpot::ParkingSpot(int spotNumber, SpotType type) : spotNumber(spotNumber), type(type), available(true), vehicle(nullptr) {}

bool ParkingSpot::isAvailable() const
{
    return available;
}

int ParkingSpot::getSpotNumber() const
{
    return spotNumber;
}

SpotType ParkingSpot::getType() const
{
    return this->type;
}

Vehicle *ParkingSpot::getParkedVehicle() const
{
    if (vehicle)
    {
        return vehicle;
    }
    return nullptr;
}

bool ParkingSpot::canFitVehicle(Vehicle *vehicle) const
{
    switch (vehicle->getType())
    {
    case VehicleType::MOTORCYCLE:
        return true;
        break;

    case VehicleType::CAR:
        return !(this->type == SpotType::COMPACT);
        break;

    case VehicleType::BUS:
    case VehicleType::TRUCK:
        return type == SpotType::LARGE;
        break;
    default:
        break;
    }

    return false;
}

bool ParkingSpot::parkVehicle(Vehicle *vehicle)
{

    if (available && canFitVehicle(vehicle))
    {
        this->vehicle = vehicle;
        available = false;
        return true;
    }

    return false;
}

Vehicle *ParkingSpot::removeVehicle()
{
    if (!vehicle)
        return nullptr;

    available = true;
    auto removedVehicle = this->vehicle;
    this->vehicle = nullptr;
    return removedVehicle;
}

void ParkingSpot::displayInfo() const
{
    cout << "Spot Number: " << this->spotNumber << '\n';
    // cout << "Type :" << this->type << '\n';

    cout << (available ? "Available" : "Occupied") << endl;

    if (vehicle)
    {
        vehicle->displayInfo();
    }
}

// int main()
// {
//     cout << "ParkingSpot main called" << endl;
//     ParkingSpot ps(1, SpotType::COMPACT);
//     ps.displayInfo();
// }