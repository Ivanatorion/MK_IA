#include "../include/Game.h"

#include <cstdio>

Game::Game(Player *player){
  this->player = player;
  state.m = NULL;
  state.gameRunning = false;
}

void Game::reset(){
  if(state.m != NULL)
    delete state.m;

  state.m = new Map();

  state.exp = 0;
  state.handMaxSize = 5;
  state.avAttack = 0;
  state.avBlock = 0;
  state.avMove = 0;
  state.avInfluence = 0;
  state.curTileN = 0;
  state.curHexN = 3;
  state.curTile = 0;
  state.curHex = state.m->getTile(0).hexes[3];

  state.isDayNight = true;

  state.gameOver = false;
}

void Game::step(ACTION action, int actionParam){
  switch (action) {
    case NOTHING:
      return;
    default:
      return;
  }
}

void Game::run(){
  ACTION nextAction;
  int nextParam;

  this->reset();
  state.avAttack = 3;
  state.gameRunning = true;

  while(!this->state.gameOver){
      this->printState();
      this->player->takeAction(state, &nextAction, &nextParam);
      this->step(nextAction, nextParam);
  }

  state.gameRunning = false;
}

void Game::printState(){
  if(!state.gameRunning){
    printf("\nGame is not running\n");
    return;
  }

  //Cards in Hand
  printf("\nCards in hand: ");
  if(state.hand.size() == 0)
    printf("None");
  else
    for(int i = 0; i < state.hand.size(); i++)
      printf("%s ", state.hand[i]->getName().c_str());
  printf("\n\n");

  //Fame
  printf("Fame: %d\n\n", state.exp);

  //Attributes
  printf("Attack: %d\nBlock: %d\nMove: %d\nInfluence: %d\n\n", state.avAttack, state.avBlock, state.avMove, state.avInfluence);

  //Location on map
  printf("Current map tile: %d\n", state.curTileN);
  printf("Current tile hex: %d\n", state.curHexN);
  printf("Hex Terrain: ");
  switch (state.curHex->terrain) {
    case HILL:
      printf("Hill");
      break;
    case PLAIN:
      printf("Plain");
      break;
    case WASTELAND:
      printf("Wasteland");
      break;
    case SWAMP:
      printf("Swamp");
      break;
    case FOREST:
      printf("Forest");
      break;
    case DESERT:
      printf("Desert");
      break;
  }
  printf("\nHex Location: ");
  switch (state.curHex->location) {
    case NONEL:
      printf("None");
      break;
    case VILLAGE:
      printf("Village");
      break;
    case GLADE:
      printf("Glade");
      break;
    case TOWER:
      printf("Tower");
      break;
    case KEEP:
      printf("Keep");
      break;
    case MONASTERY:
      printf("Monastery");
      break;
    case MINEG:
      printf("Green Mine");
      break;
    case MINEB:
      printf("Blue Mine");
      break;
    case MINER:
      printf("Red Mine");
      break;
    case MINEW:
      printf("White Mine");
      break;
    case ORC:
      printf("Orc (This should not be happening btw)");
      break;
    default:
      printf("Not defined");
  }
  printf("\n\n");

  //Map status
  printf("Map: [");
  for(int i = 0; i < NUM_TILES-1; i++)
    if((state.m->getTile(i).tileN) == -1)
      printf("? ");
    else
      printf("%d ", (state.m->getTile(i).tileN));
  if((state.m->getTile(NUM_TILES-1).tileN) == -1)
    printf("?");
  else
    printf("%d", (state.m->getTile(NUM_TILES-1).tileN));
  printf("]\n");

}
