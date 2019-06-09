#include "../../../include/Cards/ActionCards/ACMarch.h"

ACMarch::ACMarch(){
	this->color = GREEN;
	this->cardtype = ACTIONCARD;
	this->choicesWeak = 0;
  this->choicesStrong = 0;
	this->basic = true;
}

std::string ACMarch::getName(){
	return "March";
}

void ACMarch::playCardWeak(STATE *s){
	givePlayerMove(s, 2);
}

void ACMarch::playCardStrong(STATE *s){
	givePlayerMove(s, s->ConcentrationNextCard ? 6 : 4);
}
