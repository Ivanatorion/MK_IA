#include "../../include/Units/UCatapults.h"

#include "../../include/Player/Player.h"

UCatapults::UCatapults(){
  this->influenceCost = 9;
  this->armor = 4;
  this->level = 3;

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
  this->recruitableLocations.push_back(KEEP);
}

std::string UCatapults::getName(){
  return "Catapults";
}

void UCatapults::playEffect(STATE *s){

}
