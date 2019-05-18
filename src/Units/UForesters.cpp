#include "../../include/Units/UForesters.h"

#include "../../include/Player/Player.h"

UForesters::UForesters(){
  this->influenceCost = 4;
  this->armor = 4;
  this->level = 1;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 2;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(VILLAGE);
}

std::string UForesters::getName(){
  return "Foresters";
}

void UForesters::playEffect(STATE *s){

}
