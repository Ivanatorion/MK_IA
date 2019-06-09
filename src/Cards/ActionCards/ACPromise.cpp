#include "../../../include/Cards/ActionCards/ACPromise.h"

ACPromise::ACPromise(){
  this->color = WHITE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
  this->choicesStrong = 0;
  this->basic = true;
}

std::string ACPromise::getName(){
	return "Promise";
}

void ACPromise::playCardWeak(STATE *s){
  givePlayerInfluence(s, 2);
}

void ACPromise::playCardStrong(STATE *s){
  givePlayerInfluence(s, s->ConcentrationNextCard ? 6 : 4);
}
