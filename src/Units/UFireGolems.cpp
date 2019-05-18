#include "../../include/Units/UFireGolems.h"

#include "../../include/Player/Player.h"

UFireGolems::UFireGolems(){
  this->influenceCost = 8;
  this->armor = 4;
  this->level = 3;

  this->pRes = true;
  this->fRes = true;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(KEEP);
  this->recruitableLocations.push_back(TOWER);
}

std::string UFireGolems::getName(){
  return "FireGolems";
}

void UFireGolems::playEffect(STATE *s){

}
