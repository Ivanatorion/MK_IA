#include "../../include/Cards/Card.h"

void Card::givePlayerMove(STATE *s, int moveAmmount){
	s->avMove = s->avMove + moveAmmount;

	if(s->gameScene == BATTLE_RANGED && s->AgilityStrong){
		s->avRangedAttack = s->avRangedAttack + s->avMove/2;
		s->avMove = s->avMove%2;
	}

	if(s->gameScene == BATTLE_ATTACK && (s->AgilityWeak || s->AgilityStrong)){
		s->avAttack = s->avAttack + s->avMove/2;
		s->avMove = s->avMove%2;
	}
}

void Card::givePlayerAttack(STATE *s, int attackAmmount){
	s->avAttack = s->avAttack + attackAmmount;
}

void Card::givePlayerInfluence(STATE *s, int influenceAmmount){
	s->avInfluence = s->avInfluence + influenceAmmount;
}

void Card::givePlayerBlock(STATE *s, int blockAmmount){
	s->avBlock = s->avBlock + blockAmmount;
}

void Card::givePlayerHeal(STATE *s, int healAmmount){
	if(!(s->gameScene == BATTLE_RANGED || s->gameScene == BATTLE_BLOCK || s->gameScene == BATTLE_ASSIGN || s->gameScene == BATTLE_ATTACK))
		s->avHeal = s->avHeal + healAmmount;
}
