#include "../../include/Units/UDelphanaMasters.h"

#include "../../include/Player/Player.h"

UDelphanaMasters::UDelphanaMasters(){
  this->influenceCost = 13;
  this->armor = 3;
  this->level = 4;

  this->pRes = true;
  this->fRes = true;
  this->iRes = true;
  this->wounded = false;

  this->playChoices = 4;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(CITY_RED);
  this->recruitableLocations.push_back(CITY_WHITE);
  this->recruitableLocations.push_back(CITY_BLUE);
  this->recruitableLocations.push_back(CITY_GREEN);
}

std::string UDelphanaMasters::getName(){
  return "DelphanaMasters";
}

void UDelphanaMasters::playEffect(STATE *s){

}
