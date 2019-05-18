#include "../../include/Units/UUtemGuardsmen.h"

#include "../../include/Player/Player.h"

UUtemGuardsmen::UUtemGuardsmen(){
  this->influenceCost = 5;
  this->armor = 5;
  this->level = 2;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 2;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(KEEP);
  this->recruitableLocations.push_back(VILLAGE);
}

std::string UUtemGuardsmen::getName(){
  return "UtemGuardsmen";
}

void UUtemGuardsmen::playEffect(STATE *s){

}
