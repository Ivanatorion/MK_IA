#include "../../include/Units/UHerbalists.h"

#include "../../include/Player/Player.h"

UHerbalists::UHerbalists(){
  this->influenceCost = 3;
  this->armor = 2;
  this->level = 1;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(MONASTERY);
  this->recruitableLocations.push_back(VILLAGE);
}

std::string UHerbalists::getName(){
  return "Herbalists";
}

void UHerbalists::playEffect(STATE *s){

}
