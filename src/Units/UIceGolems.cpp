#include "../../include/Units/UIceGolems.h"

#include "../../include/Player/Player.h"

UIceGolems::UIceGolems(){
  this->influenceCost = 8;
  this->armor = 4;
  this->level = 3;

  this->pRes = true;
  this->fRes = false;
  this->iRes = true;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(KEEP);
  this->recruitableLocations.push_back(TOWER);
}

std::string UIceGolems::getName(){
  return "IceGolems";
}

void UIceGolems::playEffect(STATE *s){

}
