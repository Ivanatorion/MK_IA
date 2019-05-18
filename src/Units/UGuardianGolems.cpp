#include "../../include/Units/UGuardianGolems.h"

#include "../../include/Player/Player.h"

UGuardianGolems::UGuardianGolems(){
  this->influenceCost = 7;
  this->armor = 3;
  this->level = 2;

  this->pRes = true;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 4;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(KEEP);
  this->recruitableLocations.push_back(TOWER);
}

std::string UGuardianGolems::getName(){
  return "GuardianGolems";
}

void UGuardianGolems::playEffect(STATE *s){

}
