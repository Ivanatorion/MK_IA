#include "../../include/Units/USorcerers.h"

#include "../../include/Player/Player.h"

USorcerers::USorcerers(){
  this->influenceCost = 9;
  this->armor = 4;
  this->level = 3;

  this->pRes = false;
  this->fRes = true;
  this->iRes = true;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(MONASTERY);
  this->recruitableLocations.push_back(TOWER);
}

std::string USorcerers::getName(){
  return "Sorcerers";
}

void USorcerers::playEffect(STATE *s){

}
