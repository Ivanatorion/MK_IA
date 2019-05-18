#include "../../include/Units/UNorthernMonks.h"

#include "../../include/Player/Player.h"

UNorthernMonks::UNorthernMonks(){
  this->influenceCost = 7;
  this->armor = 4;
  this->level = 2;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 4;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(MONASTERY);
}

std::string UNorthernMonks::getName(){
  return "NorthernMonks";
}

void UNorthernMonks::playEffect(STATE *s){

}
