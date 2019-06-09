#include "../../../include/Cards/ActionCards/ACThreaten.h"

ACThreaten::ACThreaten(){
	this->color = RED;
	this->cardtype = ACTIONCARD;
	this->choicesWeak = 0;
  this->choicesStrong = 0;
	this->basic = true;
}

std::string ACThreaten::getName(){
	return "Threaten";
}

void ACThreaten::playCardWeak(STATE *s){
	givePlayerInfluence(s, 2);
}

void ACThreaten::playCardStrong(STATE *s){
	givePlayerInfluence(s, s->ConcentrationStrong ? 7 : 5);

	s->repToGain = s->repToGain - 1;
}
