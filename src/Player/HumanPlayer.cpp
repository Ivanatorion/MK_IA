#include "../../include/Player/HumanPlayer.h"

HumanPlayer::HumanPlayer(){

}

void HumanPlayer::takeAction(STATE state, ACTION *rAction, int *rParam){
  (*rAction) = USE_CARD_WEAK;
  (*rParam) = 0;
}

COLOR HumanPlayer::chooseBasicManaColor(){
  return WHITE;
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
