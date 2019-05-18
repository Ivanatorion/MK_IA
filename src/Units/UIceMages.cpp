#include "../../include/Units/UIceMages.h"

#include "../../include/Player/Player.h"

UIceMages::UIceMages(){
  this->influenceCost = 9;
  this->armor = 4;
  this->level = 3;

  this->pRes = false;
  this->fRes = false;
  this->iRes = true;
  this->wounded = false;

  this->playChoices = 4;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(MONASTERY);
  this->recruitableLocations.push_back(TOWER);
}

std::string UIceMages::getName(){
  return "IceMages";
}

void UIceMages::playEffect(STATE *s){

}
