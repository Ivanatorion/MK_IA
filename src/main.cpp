#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "../include/Game.h"
#include "../include/Map.h"
#include "../include/Cards/Card.h"
#include "../include/Cards/Deck.h"
#include "../include/Cards/ActionCards/ACRage.h"
#include "../include/Cards/ActionCards/ACStamina.h"
#include "../include/Player/HumanPlayer.h"

void initialize(){
  srand(time(0));
}

int main(int argc, char* argv[]){
  initialize();
  Player *player = new HumanPlayer();

  Game game(player);

  Card *c1, *c2, *c3;
  Card *drawn;
  c1 = new ACRage();
  c2 = new ACStamina();
  c3 = new ACRage();

  Deck d;
  d.addCardTop(c1);
  d.addCardTop(c2);
  d.addCardTop(c3);

  d.shuffle();
  drawn = d.drawCard();
  while(drawn != NULL){
    printf("%s\n", drawn->getName().c_str());
    drawn = d.drawCard();
  }

  //game.run();

  return 0;
}
