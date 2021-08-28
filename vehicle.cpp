#include "vehicle.h"

std::string getVehicleType(VehicleType type) {
  if (type == 0)
    return "Sedan";
  else if (type == 1)
    return "Hatchback";
  else if (type == 2)
    return "SUV";

  return "";
}

Vehicle::Vehicle(std::string plate_number, VehicleType vType) {
  this->plate_number= plate_number; 
  this->vType=vType; 
}
