#pragma once
#include<bits/stdc++.h>
#include"vehicle.h"

class Branch {
  public:
    std::string name;
    unordered_map<VehicleType, vector<Vehicle*>>vehicleInfo;
    unordered_map<VehicleType, int>pricesMap;
    Branch() {}
    Branch(std::string& name) {
      this->name = name;
    }
    void allocatePrice(VehicleType vType, int price); 
    void addVehicle(std::string& plate_number, VehicleType vType);
};
