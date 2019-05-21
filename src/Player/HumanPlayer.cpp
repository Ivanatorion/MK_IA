#include <cstdio>

#include "../../include/Player/HumanPlayer.h"

HumanPlayer::HumanPlayer(){

}

void HumanPlayer::takeAction(STATE state, ACTION *rAction, int *rParam){
  switch (state.gameScene) {
    case MOVE_AND_EXPLORE:
      takeActionMoveExplore(state, rAction, rParam);
      break;
    case BATTLE_RANGED:
    case BATTLE_BLOCK:
    case BATTLE_ATTACK:
      takeActionBattle(state, rAction, rParam);
      break;
    case BATTLE_ASSIGN:
      takeActionBattleAssign(state, rAction, rParam);
      break;
  }
}

void HumanPlayer::takeActionBattleAssign(STATE state, ACTION *rAction, int *rParam){
  int act;

  printf("Choose Action: \n\n");
  printf("00) Nothing\n");
  printf("01) Assign Damage to Unit\n");
  printf("02) Assign Damage to Player\n");
  printf("03) Advance Battle Phase\n");
  printf("04) Select Attack to Assign\n");
  printf("05) Quit Game\n");

  scanf("%d", &act);

  switch(act){
    case 0:
      (*rAction) = NOTHING;
      break;
    case 1:
      (*rAction) = ASSING_DAMAGE_TO_UNIT;
      break;
    case 2:
      (*rAction) = ASSING_DAMAGE_TO_PLAYER;
      break;
    case 3:
      (*rAction) = ADVANCE_BATTLE_PHASE;
      break;
    case 4:
      (*rAction) = SELECT_ATTACK_TO_ASSING;
      break;
    case 5:
      (*rAction) = QUIT_GAME;
      break;
  }

  printf("\nType the parameter: ");
  scanf("%d", rParam);
  printf("\n");
}

void HumanPlayer::takeActionBattle(STATE state, ACTION *rAction, int *rParam){
  int act;

  printf("Choose Action: \n\n");
  printf("00) Nothing                     07) Advance Battle Phase\n");
  printf("01) Use Card Weak               08) Quit Game\n");
  printf("02) Use Card Strong\n");
  printf("03) Use Card Sideways\n");
  printf("04) Take Die From Source\n");
  printf("05) Select Enemy\n");
  if(state.gameScene == BATTLE_BLOCK)
    printf("06) Block Selected Enemy\n");
  else
    printf("06) Attack Selected Enemies\n");

  scanf("%d", &act);

  switch(act){
    case 0:
      (*rAction) = NOTHING;
      break;
    case 1:
      (*rAction) = USE_CARD_WEAK;
      break;
    case 2:
      (*rAction) = USE_CARD_STRONG;
      break;
    case 3:
      (*rAction) = USE_CARD_SIDEWAYS;
      break;
    case 4:
      (*rAction) = TAKE_DIE_FROM_SOURCE;
      break;
    case 5:
      (*rAction) = SELECT_ENEMY;
      break;
    case 6:
      (*rAction) = (state.gameScene == BATTLE_BLOCK) ? BLOCK_ENEMY : ATTACK_SELECTED_ENEMIES;
      break;
    case 7:
      (*rAction) = ADVANCE_BATTLE_PHASE;
      break;
    case 8:
      (*rAction) = QUIT_GAME;
      break;
  }

  printf("\nType the parameter: ");
  scanf("%d", rParam);
  printf("\n");
}

void HumanPlayer::takeActionMoveExplore(STATE state, ACTION *rAction, int *rParam){
  int act;

  printf("Choose Action: \n\n");
  printf("00) Nothing                  07) Reveal Adjacent Tile\n");
  printf("01) Use Card Weak            08) Use Card Sideways\n");
  printf("02) Use Card Strong          09) Use Unit\n");
  printf("03) Take Die From Source     10) Attack Rampaging Enemy\n");
  printf("04) Move to Adjacent Hex     11) Quit Game\n");
  printf("05) End Turn\n");
  printf("06) Recruit Unit\n");

  scanf("%d", &act);

  switch(act){
    case 0:
      (*rAction) = NOTHING;
      break;
    case 1:
      (*rAction) = USE_CARD_WEAK;
      break;
    case 2:
      (*rAction) = USE_CARD_STRONG;
      break;
    case 3:
      (*rAction) = TAKE_DIE_FROM_SOURCE;
      break;
    case 4:
      (*rAction) = MOVE_TO_ADJACENT_HEX;
      break;
    case 5:
      (*rAction) = END_TURN;
      break;
    case 6:
      (*rAction) = RECRUIT_UNIT;
      break;
    case 7:
      (*rAction) = REVEAL_ADJEACENT_TILE;
      break;
    case 8:
      (*rAction) = USE_CARD_SIDEWAYS;
      break;
    case 9:
      (*rAction) = USE_UNIT;
      break;
    case 10:
      (*rAction) = ATTACK_RAMPAGING_ENEMY;
      break;
    case 11:
      (*rAction) = QUIT_GAME;
      break;
  }

  printf("\nType the parameter: ");
  scanf("%d", rParam);
  printf("\n");
}

int HumanPlayer::chooseOption(std::vector<std::string> choices){
  int res = 0;
  printf("Choose:\n\n");
  for(int i = 0; i < choices.size(); i++)
    printf("%02d) %s\n", i+1, choices[i].c_str());

  while(res < 1 || res > choices.size())
    scanf("%d", &res);

  return res - 1;
}
