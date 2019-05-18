#include "../../include/Units/UIllusionists.h"

#include "../../include/Player/Player.h"

UIllusionists::UIllusionists(){
  this->influenceCost = 7;
  this->armor = 2;
  this->level = 2;

  this->pRes = true;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(TOWER);
  this->recruitableLocations.push_back(MONASTERY);
}

std::string UIllusionists::getName(){
  return "Illusionists";
}

void UIllusionists::playEffect(STATE *s){

}
