#include "../../include/Units/Unit.h"

void Unit::tryToRecruit(STATE *s){
  LOCATION l = s->curHex->location;

  bool onValidLocation = false;
  for(int i = 0; i < this->recruitableLocations.size(); i++){
    if(this->recruitableLocations[i] == l)
      onValidLocation = true;
  }
  if(!onValidLocation || this->influenceCost > s->avInfluence)
    return;

  s->avInfluence = s->avInfluence - this->influenceCost;

  s->PlayerUnits.push_back(this);

  //If this method was called when the Unit was in the offer, everything should be fine...
  int i = 0;
  while(s->UnitOffer[i] != this)
    i++;

  s->UnitOffer.erase(s->UnitOffer.begin() + i);
}
