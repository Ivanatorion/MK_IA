#include "../../include/Units/UUtemCrossbowmen.h"

#include "../../include/Player/Player.h"

UUtemCrossbowmen::UUtemCrossbowmen(){
  this->influenceCost = 6;
  this->armor = 4;
  this->level = 2;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(KEEP);
  this->recruitableLocations.push_back(VILLAGE);
}

std::string UUtemCrossbowmen::getName(){
  return "UtemCrossbowmen";
}

void UUtemCrossbowmen::playEffect(STATE *s){

}
