#include "../../../../include/Cards/ActionCards/Advanced/ACIntimidate.h"

#include "../../../../include/Player/Player.h"

ACIntimidate::ACIntimidate(){
  this->color = RED;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 1;
	this->choicesStrong = 1;
  this->basic = false;
}

std::string ACIntimidate::getName(){
	return "Intimidate";
}

void ACIntimidate::playCardWeak(STATE *s){
  std::vector<std::string> choices;
	choices.push_back("Influence 4");
	choices.push_back("Attack 3");
	int choice = s->player->chooseOption(choices);

  s->repToGain = s->repToGain - 1;
}

void ACIntimidate::playCardStrong(STATE *s){
  std::vector<std::string> choices;
	choices.push_back("Influence 8");
	choices.push_back("Attack 7");
	int choice = s->player->chooseOption(choices);

  s->repToGain = s->repToGain - 2;

  if(choice == 0)
    givePlayerInfluence(s, s->ConcentrationStrong ? 10 : 8);
  else
    givePlayerAttack(s, s->ConcentrationStrong ? 9 : 7);
}
