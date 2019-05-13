#include <cstdio>
#include <cstdlib>

#include "../include/Game.h"

#include "../include/Cards/ActionCards/ACCrystallize.h"
#include "../include/Cards/ActionCards/ACInstinct.h"
#include "../include/Cards/ActionCards/ACColdToughness.h"
#include "../include/Cards/ActionCards/ACConcentration.h"
#include "../include/Cards/ActionCards/ACDetermination.h"
#include "../include/Cards/ActionCards/ACManaDraw.h"
#include "../include/Cards/ActionCards/ACMarch.h"
#include "../include/Cards/ActionCards/ACPromise.h"
#include "../include/Cards/ActionCards/ACRage.h"
#include "../include/Cards/ActionCards/ACStamina.h"
#include "../include/Cards/ActionCards/ACSwiftness.h"
#include "../include/Cards/ActionCards/ACThreaten.h"
#include "../include/Cards/ActionCards/ACTranquility.h"

Game::Game(Player *player){
  this->state.player = player;
  state.m = NULL;
  state.gameRunning = false;
}

std::string Game::colorToString(COLOR c){
  switch (c) {
    case RED:
      return "Red";
    case BLUE:
      return "Blue";
    case GREEN:
      return "Green";
    case WHITE:
      return "White";
    case GOLD:
      return "Gold";
    case BLACK:
      return "Black";
    default:
      return "None";
  }
}

void Game::reset(){
  if(state.m != NULL)
    delete state.m;

  state.m = new Map();

  state.currentRound = 1;
  state.exp = 0;
  state.reputation = 0;
  state.handMaxSize = 5;
  state.avAttack = 0;
  state.avBlock = 0;
  state.avMove = 0;
  state.avInfluence = 0;
  state.avHeal = 0;
  state.curTileN = 0;
  state.curHexN = 3;
  state.curTile = 0;
  state.curHex = state.m->getTile(0).hexes[3];

  state.RegularUnitsDeck.clear();
  state.EliteUnitsDeck.clear();
  state.PlayerUnits.clear();
  state.UnitOffer.clear();

  state.playerDiscardDeck.clear();
  state.playerDeedDeck.clear();
  state.advancedActionsDeck.clear();
  state.artifactsDeck.clear();
  state.spellsDeck.clear();

  state.playerTokensRed = 0;
  state.playerTokensWhite = 0;
  state.playerTokensGreen = 0;
  state.playerTokensBlue = 0;
  state.playerCrystalsRed = 0;
  state.playerCrystalsWhite = 0;
  state.playerCrystalsGreen = 0;
  state.playerCrystalsBlue = 0;

  state.ManaDrawWeakActive = false;
  state.ConcentrationNextCard = false;

  state.fameToGain = 0;
  state.repToGain = 0;

  for(int i = 0; i < N_DICE_IN_SOURCE; i++)
    rollSourceDie(i); //TODO: CHECK IF VALID START

  state.diceTaken = false;

  state.isDayNight = true;

  state.gameOver = false;

  //TODO: INIT CARDS / DECKS
  state.playerDeedDeck.addCardTop(new ACCrystallize());
  state.playerDeedDeck.addCardTop(new ACInstinct());
  state.playerDeedDeck.addCardTop(new ACColdToughness());
  state.playerDeedDeck.addCardTop(new ACDetermination());
  state.playerDeedDeck.addCardTop(new ACManaDraw());
  state.playerDeedDeck.addCardTop(new ACConcentration());
  state.playerDeedDeck.addCardTop(new ACMarch());
  state.playerDeedDeck.addCardTop(new ACMarch());
  state.playerDeedDeck.addCardTop(new ACPromise());
  state.playerDeedDeck.addCardTop(new ACRage());
  state.playerDeedDeck.addCardTop(new ACRage());
  state.playerDeedDeck.addCardTop(new ACThreaten());
  state.playerDeedDeck.addCardTop(new ACStamina());
  state.playerDeedDeck.addCardTop(new ACSwiftness());
  state.playerDeedDeck.addCardTop(new ACSwiftness());
  state.playerDeedDeck.addCardTop(new ACTranquility());
  state.playerDeedDeck.shuffle();

  for(int i = 0; i < state.handMaxSize; i++)
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
    case END_TURN:
      stepEndTurn(actionParam);
      break;
    case QUIT_GAME:
      state.gameOver = true;
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

  while(!this->state.gameOver){
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

  printf("\n################################################################################\n");
  //Cards in Hand
  printf("\nCards in hand: ");
  if(state.hand.size() == 0)
    printf("None");
  else
    for(int i = 0; i < state.hand.size(); i++)
      printf("%s ", state.hand[i]->getName().c_str());
  printf("\n\n");

  printf("Cards in Deed Deck: %d\nCards in Discard Pile: %d\n\n", state.playerDeedDeck.getSize(), state.playerDiscardDeck.getSize());

  printf("Current Round: %d\n", state.currentRound);
  //Fame
  printf("Fame: %d\nReputation: %d\n\n", state.exp, state.reputation);

  printf("Source: ");
  for(int i = 0; i < N_DICE_IN_SOURCE; i++)
    printf("%s ", colorToString(state.sourceDice[i]).c_str());


  //Attributes
  printf("\n\nAttack: %d\nBlock: %d\nMove: %d\nInfluence: %d\nHeal: %d\n\n", state.avAttack, state.avBlock, state.avMove, state.avInfluence, state.avHeal);

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
  printf("\nSpecial:\n\n");

  if(state.ManaDrawWeakActive)
    printf("Can take extra dice (ManaDraw)\n");
  if(state.ConcentrationNextCard)
    printf("Next Strong Card is empowered (Concentration)\n");

  printf("\n################################################################################\n");

}

void Game::stepUseCardWeak(int actionParam){
  bool hasMana = false;
  Card *aux;

  if(actionParam < state.hand.size())
    aux = state.hand[actionParam];
  else
    return;

  //Cant play Wounds
  if(aux->getCardType() == WOUND)
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

  //Cant play Wounds
  if(aux->getCardType() == WOUND)
    return;

  //Checks if the player have mana
  if(aux->getCardType() == ARTIFACTCARD)
    hasMana = true;
  else{
    if(aux->getCardType() == ACTIONCARD){
      if(state.ConcentrationNextCard){
        hasMana = true;
      }
      else{
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

  if(state.ConcentrationNextCard){
    aux->playCardStrong(&state);
    state.ConcentrationNextCard = false;
  }
  else{
    aux->playCardStrong(&state);
  }
}

void Game::stepTakeDieFromSource(int actionParam){
  if(actionParam >= N_DICE_IN_SOURCE || (state.diceTaken && !state.ManaDrawWeakActive))
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
      if(state.isDayNight){
        switch (state.player->chooseBasicManaColor()) {
          case RED:
            state.playerTokensRed++;
            break;
          case BLUE:
            state.playerTokensBlue++;
            break;
          case GREEN:
            state.playerTokensGreen++;
            break;
          case WHITE:
            state.playerTokensWhite++;
            break;
        }
      }
      else return;
      break;
    case BLACK:
      if(!state.isDayNight){
        state.playerTokensBlack++;
      }
      break;
    case NONE:
      return;
      break;
  }

  if(!state.diceTaken)
    state.diceTaken = true;
  else
    state.ManaDrawWeakActive = false;
  state.sourceDice[actionParam] = NONE;
}

void Game::stepEndTurn(int actionParam){
  state.diceTaken = false;
  while(state.hand.size() < state.handMaxSize && !state.playerDeedDeck.isEmpty())
    state.hand.push_back(state.playerDeedDeck.drawCard());

  state.playerTokensRed = 0;
  state.playerTokensBlue = 0;
  state.playerTokensGreen = 0;
  state.playerTokensWhite = 0;
  state.playerTokensBlack = 0;

  state.avAttack = 0;
  state.avMove = 0;
  state.avBlock = 0;
  state.avInfluence = 0;
  state.avRangedAttack = 0;
  state.avRangedIceAttack = 0;
  state.avRangedFireAttack = 0;
  state.avRangedColdFireAttack = 0;
  state.avSiegeAttack = 0;
  state.avSiegeIceAttack = 0;
  state.avSiegeFireAttack = 0;
  state.avSiegeColdFireAttack = 0;
  state.avColdFireAttack = 0;
  state.avColdFireBlock = 0;
  state.avFireAttack = 0;
  state.avFireBlock = 0;
  state.avIceAttack = 0;
  state.avIceBlock = 0;
  state.avHeal = 0;

  state.exp = state.exp + state.fameToGain;
  state.reputation = state.reputation + state.repToGain;

  state.fameToGain = 0;
  state.repToGain = 0;

  for(int i = 0; i < N_DICE_IN_SOURCE; i++)
    if(state.sourceDice[i] == NONE)
      rollSourceDie(i);

  state.ManaDrawWeakActive = false;
  state.ConcentrationNextCard = false;
}
