#include <cstdio>
#include <ctime>
#include <cstdlib>

#include "../include/Game.h"
#include "../include/Player/HumanPlayer.h"
#include "../include/Player/BotPlayer.h"
#include "../include/UserInterface/WindowsUI.h"
#include "../include/UserInterface/UbuntuUI.h"

void initialize(){
  srand(time(0));
}

int main(int argc, char* argv[]){
  initialize();
  Player *player;
  if(argc > 1)
    player = new BotPlayer(true);
  else
    player = new HumanPlayer();
    
  UserInterface *ui;

  //Changes UI based on target system
  #ifdef _WIN32
    ui = new WindowsUI();
  #elif __linux__
    ui = new UbuntuUI();
  #endif

  Game game(player, ui);

  game.run();

  return 0;
}
