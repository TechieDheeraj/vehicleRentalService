#pragma once
#include<bits/stdc++.h>
enum VehicleType { Sedan, Hatchback, SUV };

extern std::string getVehicleType(VehicleType type); 

class Vehicle {
  public:
    std::string plate_number;
    VehicleType vType;
    Vehicle() {}

    Vehicle(std::string plate_number, VehicleType vType);
};
