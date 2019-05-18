#include "../../include/Units/UShockTroops.h"

#include "../../include/Player/Player.h"

UShockTroops::UShockTroops(){
  this->influenceCost = 6;
  this->armor = 3;
  this->level = 2;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(KEEP);
}

std::string UShockTroops::getName(){
  return "ShockTroops";
}

void UShockTroops::playEffect(STATE *s){

}
