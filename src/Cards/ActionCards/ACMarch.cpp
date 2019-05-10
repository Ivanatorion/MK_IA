#include "../../../include/Cards/ActionCards/ACMarch.h"

ACMarch::ACMarch(){
	this->color = GREEN;
	this->cardtype = ACTIONCARD;
}

std::string ACMarch::getName(){
	return "March";
}

void ACMarch::playCardWeak(STATE *s){
	s->avMove = s->avMove + 2;
}

void ACMarch::playCardStrong(STATE *s){
	s->avMove = s->avMove + 4;
	
	if(s->ConcentrationNextCard)
    s->avMove = s->avMove + 2;
}
