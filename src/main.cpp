#include <cstdio>
#include <ctime>
#include <vector>

#include "../include/Game.h"
#include "../include/Map.h"
#include "../include/Cards/Card.h"
#include "../include/Cards/ActionCards/ACRage.h"

void initialize(){
  srand(time(0));
}

int main(int argc, char* argv[]){
  initialize();

  Game g;

  g.printState();

  return 0;
}
