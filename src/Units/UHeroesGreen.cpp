#include "../../include/Units/UHeroesGreen.h"

#include "../../include/Player/Player.h"

UHeroesGreen::UHeroesGreen(){
  this->influenceCost = 9;
  this->armor = 3;
  this->level = 3;

  this->pRes = true;
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

std::string UHeroesGreen::getName(){
  return "HeroesGreen";
}

void UHeroesGreen::playEffect(STATE *s){

}
