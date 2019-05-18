#include "../../include/Units/USavageMonks.h"

#include "../../include/Player/Player.h"

USavageMonks::USavageMonks(){
  this->influenceCost = 7;
  this->armor = 4;
  this->level = 2;

  this->pRes = false;
  this->fRes = false;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 3;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(MONASTERY);
}

std::string USavageMonks::getName(){
  return "SavageMonks";
}

void USavageMonks::playEffect(STATE *s){

}
