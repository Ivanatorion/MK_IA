#include "../../../../include/Cards/ActionCards/Advanced/ACBloodRage.h"
#include "../../../../include/Cards/Wound.h"
#include "../../../../include/Player/Player.h"

ACBloodRage::ACBloodRage(){
  this->color = RED;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 1;
	this->choicesStrong = 1;
  this->basic = false;
}

std::string ACBloodRage::getName(){
	return "BloodRage";
}

void ACBloodRage::playCardWeak(STATE *s){
  std::vector<std::string> choices;
	choices.push_back("Do not increase Attack to 5");
	choices.push_back("Increase Attack to 5 (Take a Wound)");
	int choice = s->player->chooseOption(choices);

  if(choice == 1){
    givePlayerAttack(s, 5);
    s->playerHand.push_back(new Wound());
  }
  else
    givePlayerAttack(s, 2);
}

void ACBloodRage::playCardStrong(STATE *s){
  std::vector<std::string> choices;
	choices.push_back("Do not increase Attack to 9");
	choices.push_back("Increase Attack to 9 (Take a Wound)");
	int choice = s->player->chooseOption(choices);

  if(choice == 1){
    givePlayerAttack(s, s->ConcentrationStrong ? 11 : 9);
    s->playerHand.push_back(new Wound());
  }
  else
    givePlayerAttack(s, s->ConcentrationStrong ? 6 : 4);
}
