#include "../../include/Units/UHeroesBlue.h"

#include "../../include/Player/Player.h"

UHeroesBlue::UHeroesBlue(){
  this->influenceCost = 9;
  this->armor = 4;
  this->level = 3;

  this->pRes = false;
  this->fRes = false;
  this->iRes = true;
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

std::string UHeroesBlue::getName(){
  return "HeroesBlue";
}

void UHeroesBlue::playEffect(STATE *s){

}
