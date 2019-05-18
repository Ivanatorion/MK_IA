#include "../../include/Units/UFireMages.h"

#include "../../include/Player/Player.h"

UFireMages::UFireMages(){
  this->influenceCost = 9;
  this->armor = 4;
  this->level = 3;

  this->pRes = false;
  this->fRes = true;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 4;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(MONASTERY);
  this->recruitableLocations.push_back(TOWER);
}

std::string UFireMages::getName(){
  return "FireMages";
}

void UFireMages::playEffect(STATE *s){

}
