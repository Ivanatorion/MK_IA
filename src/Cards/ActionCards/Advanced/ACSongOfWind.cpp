#include "../../../../include/Cards/ActionCards/Advanced/ACSongOfWind.h"

#include "../../../../include/Player/Player.h"

ACSongOfWind::ACSongOfWind(){
  this->color = WHITE;
  this->cardtype = ACTIONCARD;
  this->choicesWeak = 0;
	this->choicesStrong = 1;
  this->basic = false;
}

std::string ACSongOfWind::getName(){
	return "SongOfWind";
}

void ACSongOfWind::playCardWeak(STATE *s){
	s->SongOfWindWeak = true;
  givePlayerMove(s, 2);
}

void ACSongOfWind::playCardStrong(STATE *s){
  std::vector<std::string> choices;
	choices.push_back("Pay a Blue Mana to travel through Lakes");
	choices.push_back("Do not pay a Blue Mana");
	int choice = s->player->chooseOption(choices);

  if(choice == 0){
    if(s->playerTokensBlue > 0){
      s->playerTokensBlue--;
      s->SongOfWindStrongBlue = true;
    }
    else if(s->playerCrystalsBlue > 0){
      s->playerCrystalsBlue--;
      s->SongOfWindStrongBlue = true;
    }
  }

  s->SongOfWindStrong = true;
  givePlayerMove(s, s->ConcentrationStrong ? 6 : 4);
}
