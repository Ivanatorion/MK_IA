#include "../../include/Units/UHeroesWhite.h"

#include "../../include/Player/Player.h"

UHeroesWhite::UHeroesWhite(){
  this->influenceCost = 9;
  this->armor = 6;
  this->level = 3;

  this->pRes = false;
  this->fRes = false;
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

std::string UHeroesWhite::getName(){
  return "HeroesWhite";
}

void UHeroesWhite::playEffect(STATE *s){

}
