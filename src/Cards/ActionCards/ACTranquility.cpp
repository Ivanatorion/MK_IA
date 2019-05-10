#include "../../../include/Cards/ActionCards/ACTranquility.h"

#include "../../../include/Player/Player.h"

ACTranquility::ACTranquility(){
	this->color = GREEN;
	this->cardtype = ACTIONCARD;
}

std::string ACTranquility::getName(){
	return "Tranquility";
}

void ACTranquility::playCardWeak(STATE *s){
	std::vector<std::string> choices;
	choices.push_back("Heal 1");
	choices.push_back("Draw 1 Card");

	int c = s->player->chooseOption(choices);

	switch (c) {
		case 0:
			s->avHeal = s->avHeal + 1;
			break;
		case 1:
			if(!s->playerDeedDeck.isEmpty())
				s->hand.push_back(s->playerDeedDeck.drawCard());
			break;
	}
}

void ACTranquility::playCardStrong(STATE *s){
	std::vector<std::string> choices;
	choices.push_back("Heal 2");
	choices.push_back("Draw 2 Cards");

	int c = s->player->chooseOption(choices);

	switch (c) {
		case 0:
			s->avHeal = s->avHeal + 2;
			break;
		case 1:
			if(!s->playerDeedDeck.isEmpty())
				s->hand.push_back(s->playerDeedDeck.drawCard());
			if(!s->playerDeedDeck.isEmpty())
				s->hand.push_back(s->playerDeedDeck.drawCard());
			break;
	}
}
