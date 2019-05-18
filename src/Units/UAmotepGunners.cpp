#include "../../include/Units/UAmotepGunners.h"

#include "../../include/Player/Player.h"

UAmotepGunners::UAmotepGunners(){
  this->influenceCost = 8;
  this->armor = 6;
  this->level = 3;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 2;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(CITY_RED);
  this->recruitableLocations.push_back(CITY_WHITE);
  this->recruitableLocations.push_back(CITY_BLUE);
  this->recruitableLocations.push_back(CITY_GREEN);
  this->recruitableLocations.push_back(KEEP);
}

std::string UAmotepGunners::getName(){
  return "AmotepGunners";
}

void UAmotepGunners::playEffect(STATE *s){

}
