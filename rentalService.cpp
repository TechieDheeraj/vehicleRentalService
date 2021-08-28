#include "vehicle.h"
#include "branch.h"
#include "rentalService.h"

void RentalService::addBranch(std::string branch) {
  if (hm.find(branch) != hm.end()) {
    cout << "Branch already exists" << endl;
    return;
  }
  hm[branch] = new Branch(branch); 
}

Branch* RentalService::getBranch(std::string& name) {
  if (hm.find(name) != hm.end()) {
    return hm[name];
  }
  return nullptr;
}

void RentalService::allocatePrice(std::string branchName, VehicleType vType, int price) {
  Branch *BranchObj = getBranch(branchName);
  BranchObj->allocatePrice(vType, price);
  pqV[vType].push(make_pair(price, branchName));
}

std::string RentalService::bookVehicle(VehicleType vType, std::string startTime, std::string endTime) {

  std::string res = "";
  Vehicle* vObj;
  std::string branchName =""; 
  for (int i = 0;i < hm.size(); ++i) { // iterate on branches 
    auto branchPair = pqV[vType].top();
    pqV[vType].pop();
    branchName = branchPair.second;
    auto it = hm[branchName];
    if (it->vehicleInfo[vType].size() >= 1) {
      vObj = it->vehicleInfo[vType].back();
      it->vehicleInfo[vType].pop_back();
      break;
    }
  }
  res = "Vehicle: " + vObj->plate_number + " (" +  getVehicleType(vObj->vType) + ")" + " from " + branchName + " booked ";
  return res;
}

void RentalService::addVehicle(std::string plate_number, VehicleType vType, std::string branch) {
  Branch *BranchObj = getBranch(branch);
  if (!BranchObj) {
    cout << "Entered Invalid Branch" << endl;
    return;
  }
  BranchObj->addVehicle(plate_number, vType);
}

void RentalService::printInventory() {

  for(auto it = hm.begin(); it != hm.end(); ++it) {
    cout << " ********* Branch: " << it->first << " ************ " << endl;
    auto vInfo = it->second->vehicleInfo; 
    auto vPrice = it->second->pricesMap; 
    for (auto itt = vInfo.begin(); itt != vInfo.end(); ++itt) { 
      cout << "\t VehicleType: " << getVehicleType(itt->first) << ", Price: " << vPrice[itt->first] << endl;
      auto arr = itt->second;
      for (int i = 0;i < arr.size(); ++i) {
        cout << "\t\t Vehicle: " << arr[i]->plate_number << endl;
      }
    }
  }
  cout << "\n";
}
