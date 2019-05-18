#include "../../include/Units/UAltemMages.h"

#include "../../include/Player/Player.h"

UAltemMages::UAltemMages(){
  this->influenceCost = 12;
  this->armor = 5;
  this->level = 4;

  this->pRes = false;
  this->fRes = true;
  this->iRes = true;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(CITY_RED);
  this->recruitableLocations.push_back(CITY_WHITE);
  this->recruitableLocations.push_back(CITY_BLUE);
  this->recruitableLocations.push_back(CITY_GREEN);
}

std::string UAltemMages::getName(){
  return "AltemMages";
}

void UAltemMages::playEffect(STATE *s){

}
