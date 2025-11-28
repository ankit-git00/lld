#include "parking_lot.hpp"

ParkingLot::ParkingLot(int numCompact, int numRegular, int numLarge) : capacity(numCompact + numRegular + numLarge), availableSpots(capacity)
{
    int spotNumber = 1;
    for (int i = 0; i < numCompact; i++)
    {
        spots.push_back(new ParkingSpot(spotNumber++, SpotType::COMPACT));
    }

    for (int i = 0; i < numRegular; i++)
    {
        spots.push_back(new ParkingSpot(spotNumber++, SpotType::REGULAR));
    }

    for (int i = 0; i < numLarge; i++)
    {
        spots.push_back(new ParkingSpot(spotNumber++, SpotType::LARGE));
    }
}

int ParkingLot::getCapacity() const
{
    return capacity;
}

int ParkingLot::getAvailableSpots() const
{
    return availableSpots;
}

ParkingSpot *ParkingLot::findAvailableSpot(Vehicle *vehicle) const
{

    for (auto spot : spots)
    {
        if (spot->isAvailable() && spot->canFitVehicle(vehicle))
        {
            return spot;
        }
    }
    return nullptr;
}

bool ParkingLot::parkVehicle(Vehicle *vehicle)
{
    if (!vehicle)
    {
        return false;
    }

    if (occupiedSpots.find(vehicle->getLicensePlate()) != occupiedSpots.end())
    {
        return false;
    }
    ParkingSpot *spot = findAvailableSpot(vehicle);
    if (!spot)
    {
        return false;
    }

    if (spot->parkVehicle(vehicle))
    {

        occupiedSpots[vehicle->getLicensePlate()] = spot;
        availableSpots--;
        return true;
    }

    return false;
}

Vehicle *ParkingLot::unParkVehicle(string licensePlate)
{
    auto it = occupiedSpots.find(licensePlate);
    if (it == occupiedSpots.end())
    {
        return nullptr;
    }
    ParkingSpot *spot = it->second;
    Vehicle *vehicle = spot->removeVehicle();

    if (vehicle)
    {
        occupiedSpots.erase(it);
        availableSpots++;
        return vehicle;
    }

    return nullptr;
}

void ParkingLot::displayInfo() const
{
    cout << "Parking Lot Capacity: " << capacity << endl;
    cout << "Available Spots: " << availableSpots << endl;
    cout << "Occupied Spots: " << capacity - availableSpots << endl;
}

Vehicle *ParkingLot::findVehicle(string licensePlate) const
{
    auto it = occupiedSpots.find(licensePlate);

    if (it == occupiedSpots.end())
    {
        return nullptr;
    }

    return it->second->getParkedVehicle();
}
