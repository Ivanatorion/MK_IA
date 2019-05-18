#include "../../include/Units/UThugs.h"

#include "../../include/Player/Player.h"

UThugs::UThugs(){
  this->influenceCost = 5;
  this->armor = 5;
  this->level = 1;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(VILLAGE);
  this->recruitableLocations.push_back(KEEP);
}

std::string UThugs::getName(){
  return "Thugs";
}

void UThugs::playEffect(STATE *s){

}
