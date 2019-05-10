#include "../../../include/Cards/ActionCards/ACThreaten.h"

ACThreaten::ACThreaten(){
	this->color = RED;
	this->cardtype = ACTIONCARD;
}

std::string ACThreaten::getName(){
	return "Threaten";
}

void ACThreaten::playCardWeak(STATE *s){

}

void ACThreaten::playCardStrong(STATE *s){

}