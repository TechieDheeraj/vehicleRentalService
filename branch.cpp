#include"vehicle.h"
#include"branch.h"

void Branch::allocatePrice(VehicleType vType, int price) {
  pricesMap[vType] = price;
}

void Branch::addVehicle(std::string& plate_number, VehicleType vType) {
  Vehicle *vObj = new Vehicle(plate_number, vType);
  vehicleInfo[vType].push_back(vObj); // adding vehicle to branch
}
