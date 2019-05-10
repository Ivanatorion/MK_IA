#include "../include/Game.h"

#include "../include/Cards/ActionCards/ACCrystallize.h"
#include "../include/Cards/ActionCards/ACInstinct.h"

#include <cstdio>

Game::Game(Player *player){
  this->state.player = player;
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

  state.playerDiscardDeck.clear();
  state.playerDeedDeck.clear();
  state.advancedActionsDeck.clear();
  state.artifactsDeck.clear();
  state.spellsDeck.clear();

  state.playerTokensRed = 0;
  state.playerTokensWhite = 2;
  state.playerTokensGreen = 2;
  state.playerTokensBlue = 1;
  state.playerCrystalsRed = 0;
  state.playerCrystalsWhite = 0;
  state.playerCrystalsGreen = 0;
  state.playerCrystalsBlue = 0;

  for(int i = 0; i < N_DICE_IN_SOURCE; i++)
    rollSourceDie(i); //TODO: CHECK IF VALID START

  state.diceTaken = false;

  state.isDayNight = true;

  state.gameOver = false;

  //TODO: INIT CARDS / DECKS
  state.playerDeedDeck.addCardTop(new ACCrystallize());
  state.playerDeedDeck.addCardTop(new ACInstinct());
  state.hand.push_back(state.playerDeedDeck.drawCard());
  state.hand.push_back(state.playerDeedDeck.drawCard());
}

void Game::rollSourceDie(int dieN){
  switch (rand()%6) {
    case 0:
      state.sourceDice[dieN] = RED;
      break;
    case 1:
      state.sourceDice[dieN] = GREEN;
      break;
    case 2:
      state.sourceDice[dieN] = BLUE;
      break;
    case 3:
      state.sourceDice[dieN] = WHITE;
      break;
    case 4:
      state.sourceDice[dieN] = BLACK;
      break;
    case 5:
      state.sourceDice[dieN] = GOLD;
      break;
  }
}

void Game::step(ACTION action, int actionParam){
  switch (action) {
    case USE_CARD_WEAK:
      stepUseCardWeak(actionParam);
      break;
    case USE_CARD_STRONG:
      stepUseCardStrong(actionParam);
      break;
    case TAKE_DIE_FROM_SOURCE:
      stepTakeDieFromSource(actionParam);
      break;
    default:
      return;
  }
}

void Game::run(){
  ACTION nextAction;
  int nextParam;

  this->reset();
  state.gameRunning = true;

  int limit = 2;
  while(!this->state.gameOver && limit-- > 0){
      this->printState();
      this->state.player->takeAction(state, &nextAction, &nextParam);
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

  printf("\nCrystals:\nRed: %d\nBlue: %d\nGreen: %d\nWhite: %d\n", state.playerCrystalsRed, state.playerCrystalsBlue, state.playerCrystalsGreen, state.playerCrystalsWhite);
  printf("\nTokens:\nRed: %d\nBlue: %d\nGreen: %d\nWhite: %d\n", state.playerTokensRed, state.playerTokensBlue, state.playerTokensGreen, state.playerTokensWhite);

  printf("\n################################################################################\n");

}

void Game::stepUseCardWeak(int actionParam){
  bool hasMana = false;
  Card *aux;

  if(actionParam < state.hand.size())
    aux = state.hand[actionParam];
  else
    return;

  //Checks if the player have mana
  if(aux->getCardType() == ARTIFACTCARD || aux->getCardType() == ACTIONCARD)
    hasMana = true;
  else{
    if(aux->getCardType() == SPELLCARD){
      switch(aux->getColor()){
        case RED:
          hasMana = (state.playerCrystalsRed > 0 || state.playerTokensRed > 0);
          if(!hasMana)
            return;
          if(state.playerTokensRed > 0)
            state.playerTokensRed--;
          else
            state.playerCrystalsRed--;
          break;
        case BLUE:
          hasMana = (state.playerCrystalsBlue > 0 || state.playerTokensBlue > 0);
          if(!hasMana)
            return;
          if(state.playerTokensBlue > 0)
            state.playerTokensBlue--;
          else
            state.playerCrystalsBlue--;
          break;
        case GREEN:
          hasMana = (state.playerCrystalsGreen > 0 || state.playerTokensGreen > 0);
          if(!hasMana)
            return;
          if(state.playerTokensGreen > 0)
            state.playerTokensGreen--;
          else
            state.playerCrystalsGreen--;
          break;
        case WHITE:
          hasMana = (state.playerCrystalsWhite > 0 || state.playerTokensWhite > 0);
          if(!hasMana)
            return;
          if(state.playerTokensWhite > 0)
            state.playerTokensWhite--;
          else
            state.playerCrystalsWhite--;
          break;
      }
    }
  }

  state.playerDiscardDeck.addCardTop(aux);
  state.hand.erase(state.hand.begin() + actionParam);
  aux->playCardWeak(&state);
}

void Game::stepUseCardStrong(int actionParam){
  bool hasMana = false;
  Card *aux;

  if(actionParam < state.hand.size())
    aux = state.hand[actionParam];
  else
    return;

  //Checks if the player have mana
  if(aux->getCardType() == ARTIFACTCARD)
    hasMana = true;
  else{
    if(aux->getCardType() == ACTIONCARD){
      switch(aux->getColor()){
        case RED:
          hasMana = (state.playerCrystalsRed > 0 || state.playerTokensRed > 0);
          if(!hasMana)
            return;
          if(state.playerTokensRed > 0)
            state.playerTokensRed--;
          else
            state.playerCrystalsRed--;
          break;
        case BLUE:
          hasMana = (state.playerCrystalsBlue > 0 || state.playerTokensBlue > 0);
          if(!hasMana)
            return;
          if(state.playerTokensBlue > 0)
            state.playerTokensBlue--;
          else
            state.playerCrystalsBlue--;
          break;
        case GREEN:
          hasMana = (state.playerCrystalsGreen > 0 || state.playerTokensGreen > 0);
          if(!hasMana)
            return;
          if(state.playerTokensGreen > 0)
            state.playerTokensGreen--;
          else
            state.playerCrystalsGreen--;
          break;
        case WHITE:
          hasMana = (state.playerCrystalsWhite > 0 || state.playerTokensWhite > 0);
          if(!hasMana)
            return;
          if(state.playerTokensWhite > 0)
            state.playerTokensWhite--;
          else
            state.playerCrystalsWhite--;
          break;
      }
    }
    else{
      if(aux->getCardType() == SPELLCARD){
        switch(aux->getColor()){
          case RED:
            hasMana = (state.playerTokensBlack > 0 && !state.isDayNight && (state.playerCrystalsRed > 0 || state.playerTokensRed > 0));
            if(!hasMana)
              return;
            state.playerTokensBlack--;
            if(state.playerTokensRed > 0)
              state.playerTokensRed--;
            else
              state.playerCrystalsRed--;
            break;
          case BLUE:
            hasMana = (state.playerTokensBlack > 0 && !state.isDayNight && (state.playerCrystalsBlue > 0 || state.playerTokensBlue > 0));
            if(!hasMana)
              return;
            state.playerTokensBlack--;
            if(state.playerTokensBlue > 0)
              state.playerTokensBlue--;
            else
              state.playerCrystalsBlue--;
            break;
          case GREEN:
            hasMana = (state.playerTokensBlack > 0 && !state.isDayNight && (state.playerCrystalsGreen > 0 || state.playerTokensGreen > 0));
            if(!hasMana)
              return;
            state.playerTokensBlack--;
            if(state.playerTokensGreen > 0)
              state.playerTokensGreen--;
            else
              state.playerCrystalsGreen--;
            break;
          case WHITE:
            hasMana = (state.playerTokensBlack > 0 && !state.isDayNight && (state.playerCrystalsWhite > 0 || state.playerTokensWhite > 0));
            if(!hasMana)
              return;
            state.playerTokensBlack--;
            if(state.playerTokensWhite > 0)
              state.playerTokensWhite--;
            else
              state.playerCrystalsWhite--;
            break;
        }
      }
    }
  }

  state.playerDiscardDeck.addCardTop(aux);
  state.hand.erase(state.hand.begin() + actionParam);
  aux->playCardStrong(&state);
}

void Game::stepTakeDieFromSource(int actionParam){
  if(actionParam < N_DICE_IN_SOURCE)
    return;

  switch (state.sourceDice[actionParam]) {
    case RED:
      state.playerTokensRed++;
      break;
    case GREEN:
      state.playerTokensGreen++;
      break;
    case BLUE:
      state.playerTokensBlue++;
      break;
    case WHITE:
      state.playerTokensWhite++;
      break;
    case GOLD:
      //TODO: PLAYER MUST CHOOSE
      break;
    case BLACK:
      return;
  }

  rollSourceDie(actionParam);
}
