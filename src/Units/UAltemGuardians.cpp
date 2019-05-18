#include "../../include/Units/UAltemGuardians.h"

#include "../../include/Player/Player.h"

UAltemGuardians::UAltemGuardians(){
  this->influenceCost = 11;
  this->armor = 7;
  this->level = 4;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(CITY_RED);
  this->recruitableLocations.push_back(CITY_WHITE);
  this->recruitableLocations.push_back(CITY_BLUE);
  this->recruitableLocations.push_back(CITY_GREEN);
}

std::string UAltemGuardians::getName(){
  return "AltemGuardians";
}

void UAltemGuardians::playEffect(STATE *s){

}
