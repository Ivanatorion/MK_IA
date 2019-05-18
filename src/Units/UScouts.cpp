#include "../../include/Units/UScouts.h"

#include "../../include/Player/Player.h"

UScouts::UScouts(){
  this->influenceCost = 4;
  this->armor = 2;
  this->level = 1;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(VILLAGE);
  this->recruitableLocations.push_back(KEEP);
  this->recruitableLocations.push_back(TOWER);
  this->recruitableLocations.push_back(MONASTERY);
  this->recruitableLocations.push_back(CITY_RED);
  this->recruitableLocations.push_back(CITY_WHITE);
  this->recruitableLocations.push_back(CITY_BLUE);
  this->recruitableLocations.push_back(CITY_GREEN);
}

std::string UScouts::getName(){
  return "Scouts";
}

void UScouts::playEffect(STATE *s){

}
