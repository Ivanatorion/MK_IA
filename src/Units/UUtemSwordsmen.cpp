#include "../../include/Units/UUtemSwordsmen.h"

#include "../../include/Player/Player.h"

UUtemSwordsmen::UUtemSwordsmen(){
  this->influenceCost = 6;
  this->armor = 4;
  this->level = 2;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 4;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(KEEP);
}

std::string UUtemSwordsmen::getName(){
  return "UtemSwordsmen";
}

void UUtemSwordsmen::playEffect(STATE *s){

}
