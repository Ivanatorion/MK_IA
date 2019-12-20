#include "../../include/Units/Unit.h"

Unit::~Unit(){};

void Unit::tryToRecruit(STATE *s){
  bool onValidLocation = false;

  for(int i = 0; i < this->recruitableLocations.size(); i++){
    if(this->recruitableLocations[i] == s->curHex->location)
      onValidLocation = true;
  }
  if(!onValidLocation || this->influenceCost > s->avInfluence)
    return;

  int i = 0;
  while(s->UnitOffer[i] != this && i <  s->UnitOffer.size())
    i++;

  if(i < s->UnitOffer.size()){
    s->UnitOffer.erase(s->UnitOffer.begin() + i);
    s->PlayerUnits.push_back(this);
    s->avInfluence = s->avInfluence - this->influenceCost;
  }
}
