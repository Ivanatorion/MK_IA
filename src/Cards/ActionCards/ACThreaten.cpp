#include "../../../include/Cards/ActionCards/ACThreaten.h"

ACThreaten::ACThreaten(){
	this->color = RED;
	this->cardtype = ACTIONCARD;
	this->choicesWeak = 0;
  this->choicesStrong = 0;
}

std::string ACThreaten::getName(){
	return "Threaten";
}

void ACThreaten::playCardWeak(STATE *s){
	s->avInfluence = s->avInfluence + 2;
}

void ACThreaten::playCardStrong(STATE *s){
	s->avInfluence = s->avInfluence + 5;

	if(s->ConcentrationNextCard)
		s->avInfluence = s->avInfluence + 2;

	s->repToGain = s->repToGain - 1;
}
