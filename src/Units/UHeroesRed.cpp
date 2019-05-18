#include "../../include/Units/UHeroesRed.h"

#include "../../include/Player/Player.h"

UHeroesRed::UHeroesRed(){
  this->influenceCost = 9;
  this->armor = 4;
  this->level = 3;

  this->pRes = false;
  this->fRes = true;
  this->iRes = false;
  this->wounded = false;

  this->playChoices = 4;

  this->recruitableLocations.clear();
  this->recruitableLocations.push_back(CITY_RED);
  this->recruitableLocations.push_back(CITY_WHITE);
  this->recruitableLocations.push_back(CITY_BLUE);
  this->recruitableLocations.push_back(CITY_GREEN);
  this->recruitableLocations.push_back(KEEP);
  this->recruitableLocations.push_back(VILLAGE);
}

std::string UHeroesRed::getName(){
  return "HeroesRed";
}

void UHeroesRed::playEffect(STATE *s){

}
