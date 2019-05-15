#include <cstdio>

#include "../../include/Player/HumanPlayer.h"

HumanPlayer::HumanPlayer(){

}

void HumanPlayer::takeAction(STATE state, ACTION *rAction, int *rParam){
  int act;

  printf("Choose Action: \n\n");
  printf("00) Nothing                  07) Quit Game\n");
  printf("01) Use Card Weak\n");
  printf("02) Use Card Strong\n");
  printf("03) Take Die From Source\n");
  printf("04) Move to Adjacent Hex\n");
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
