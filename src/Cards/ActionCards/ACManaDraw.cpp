#include "../../../include/Cards/ActionCards/ACManaDraw.h"

ACManaDraw::ACManaDraw(){
	this->color = WHITE;
	this->cardtype = ACTIONCARD;
}

std::string ACManaDraw::getName(){
	return "Mana Draw";
}

void ACManaDraw::playCardWeak(STATE *s){

}

void ACManaDraw::playCardStrong(STATE *s){

}
