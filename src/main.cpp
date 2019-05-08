#include <cstdio>
#include <vector>
#include "../include/Game.h"
#include "../include/Map.h"
#include "../include/Cards/Card.h"
#include "../include/Cards/ActionCards/ACRage.h"

int main(int argc, char* argv[]){
  Game g;

  STATE s = g.getState();

  printf("Cards in hand: %d/%d\n", (int) s.hand.size(), s.handMaxSize);
  printf("\n");

  return 0;
}
