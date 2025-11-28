#include "vehicle.hpp"

Vehicle::Vehicle(string licensePlate, VehicleType type, string color) : licensePlate(licensePlate), type(type), color(color) {}

string Vehicle::getColor() const
{
    return color;
}

string Vehicle::getLicensePlate() const
{
    return licensePlate;
}

VehicleType Vehicle::getType() const
{
    return type;
}

void Vehicle::displayInfo() const
{
    cout << "Vehicle : " << color << " ";
    switch (type)
    {
    case VehicleType::CAR:
        cout << "Car";
        break;

    case VehicleType::MOTORCYCLE:
        cout << "Motorcycle";
        break;

    case VehicleType::BUS:
        cout << "Bus";
        break;
    default:
        break;
    }

    cout << "LicensePlate : " << licensePlate << '\n';
}
