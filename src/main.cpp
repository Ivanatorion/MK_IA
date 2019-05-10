#include <cstdio>
#include <ctime>
#include <cstdlib>

#include "../include/Game.h"
#include "../include/Player/HumanPlayer.h"

void initialize(){
  srand(time(0));
}

int main(int argc, char* argv[]){
  initialize();
  Player *player = new HumanPlayer();

  Game game(player);

  game.run();

  return 0;
}
