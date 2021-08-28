#pragma once

#include"branch.h"
#include"vehicle.h"

class cmp {
  public:
    bool operator() (pair<int, std::string>& l,pair<int, std::string> &r) {
      return l.first > r.first;
    }
};

class RentalService {
  private:
    unordered_map<std::string, Branch*>hm;
    std::vector<priority_queue<pair<int, std::string>, std::vector<pair<int, std::string>>, cmp>>pqV{3};

  public:
    void addBranch(std::string branch);
    Branch* getBranch(std::string& name);
    void printInventory();
    void addVehicle(std::string plate_number, VehicleType vType, std::string branch);
    void allocatePrice(std::string branchName, VehicleType vType, int price);
    std::string bookVehicle(VehicleType vType, std::string startTime, std::string endTime);
};
