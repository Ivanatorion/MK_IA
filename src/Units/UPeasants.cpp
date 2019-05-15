#include "../../include/Units/UPeasants.h"

UPeasants::UPeasants(){
  this->influenceCost = 4;
  this->armor = 1;
  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;
  this->level = 1;

  this->playChoices = 4;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(VILLAGE);
}

std::string UPeasants::getName(){
  return "Peasants";
}

void UPeasants::playEffect(STATE *s){

}
