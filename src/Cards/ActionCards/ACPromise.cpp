#include "../../../include/Cards/ActionCards/ACPromise.h"

ACPromise::ACPromise(){
	this->color = WHITE;
	this->cardtype = ACTIONCARD;
}

std::string ACPromise::getName(){
	return "Promise";
}

void ACPromise::playCardWeak(STATE *s){
	s->avInfluence = s->avInfluence + 2;
}

void ACPromise::playCardStrong(STATE *s){
	s->avInfluence = s->avInfluence + 4;
}
