#include<bits/stdc++.h>
#include "vehicle.h"
#include "branch.h"
#include "rentalService.h"

int main() {

  RentalService mainObj;
  mainObj.addBranch("Vasanth Vihar");
  mainObj.addBranch("Cyber City");
  mainObj.allocatePrice("Vasanth Vihar", Sedan, 100);
  mainObj.allocatePrice("Vasanth Vihar", Hatchback, 80);
  mainObj.allocatePrice("Cyber City", Sedan, 200);
  mainObj.allocatePrice("Cyber City", Hatchback, 50);
  mainObj.addVehicle("DL 01 MR 9310", Sedan, "Vasanth Vihar");
  mainObj.addVehicle("DL 01 MR 9311", Sedan, "Cyber City");
  mainObj.addVehicle("DL 01 MR 9312", Hatchback, "Cyber City");
  mainObj.printInventory();
  cout <<  mainObj.bookVehicle(Sedan, "29-02-2020 10:00 AM", "29-02-2020 01:00 PM") << endl;;
  cout <<  mainObj.bookVehicle(Hatchback, "29-02-2020 10:00 AM", "29-02-2020 01:00 PM") << endl;;
  return 0;
}
