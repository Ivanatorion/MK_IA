#include "../../../include/Cards/ActionCards/ACConcentration.h"

ACConcentration::ACConcentration(){
	this->color = RED;
	this->cardtype = ACTIONCARD;
}

std::string ACConcentration::getName(){
	return "Concentration";
}

void ACConcentration::playCardWeak(STATE *s){

}

void ACConcentration::playCardStrong(STATE *s){

}