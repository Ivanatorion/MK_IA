#include <cstdio>

#include "../../include/Player/HumanPlayer.h"

HumanPlayer::HumanPlayer(){

}

void HumanPlayer::takeAction(STATE state, ACTION *rAction, int *rParam){
  int act;

  printf("Choose Action: \n\n");
  printf("00) Nothing\n");
  printf("01) Use Card Weak\n");
  printf("02) Use Card Strong\n");
  printf("03) Take Die From Source\n");
  printf("04) End Turn\n");
  printf("05) Quit Game\n");

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
      (*rAction) = END_TURN;
      break;
    case 5:
      (*rAction) = QUIT_GAME;
      break;
  }

  printf("\nType the parameter: ");
  scanf("%d", rParam);
  printf("\n");
}

COLOR HumanPlayer::chooseBasicManaColor(){
  int c;
  printf("Choose Mana Color:\n\n");
  printf("00) Red\n01) Blue\n02) Green\n03) White\n");

  do{
    scanf("%d", &c);
  }while(c < 0 || c > 3);

  switch (c) {
    case 0:
      return RED;
    case 1:
      return BLUE;
    case 2:
      return GREEN;
    case 3:
      return WHITE;
  }

  return NONE; //Should not happen
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
