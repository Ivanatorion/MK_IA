#include "../../../include/Cards/ActionCards/ACPromise.h"

ACPromise::ACPromise(){
  this->color = WHITE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
  this->choicesStrong = 0;
}

std::string ACPromise::getName(){
	return "Promise";
}

void ACPromise::playCardWeak(STATE *s){
  s->avInfluence = s->avInfluence + 2;
}

void ACPromise::playCardStrong(STATE *s){
  s->avInfluence = s->avInfluence + 4;

  if(s->ConcentrationNextCard)
    s->avInfluence = s->avInfluence + 2;
}
