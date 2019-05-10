#include "../../include/Cards/Wound.h"

Wound::Wound(){
	this->color = NONE;
	this->cardtype = WOUND;
}

std::string Wound::getName(){
	return "WOUND";
}

void Wound::playCardWeak(STATE *s){
  //Never Happens
}

void Wound::playCardStrong(STATE *s){
  //Never Happens
}
