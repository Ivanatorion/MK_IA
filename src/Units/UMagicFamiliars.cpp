#include "../../include/Units/UMagicFamiliars.h"

#include "../../include/Player/Player.h"

UMagicFamiliars::UMagicFamiliars(){
  this->influenceCost = 6;
  this->armor = 5;
  this->level = 2;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 5;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(TOWER);
  this->recruitableLocations.push_back(MONASTERY);
  this->recruitableLocations.push_back(GLADE);
}

std::string UMagicFamiliars::getName(){
  return "MagicFamiliars";
}

void UMagicFamiliars::playEffect(STATE *s){

}
