#include <cstdio>
#include <cstdlib>

#include "../include/Game.h"

#include "../include/Units/UAltemGuardians.h"
#include "../include/Units/UAltemMages.h"
#include "../include/Units/UAmotepFreezers.h"
#include "../include/Units/UAmotepGunners.h"
#include "../include/Units/UCatapults.h"
#include "../include/Units/UDelphanaMasters.h"
#include "../include/Units/UFireGolems.h"
#include "../include/Units/UFireMages.h"
#include "../include/Units/UForesters.h"
#include "../include/Units/UGuardianGolems.h"
#include "../include/Units/UHerbalists.h"
#include "../include/Units/UHeroesBlue.h"
#include "../include/Units/UHeroesGreen.h"
#include "../include/Units/UHeroesRed.h"
#include "../include/Units/UHeroesWhite.h"
#include "../include/Units/UIceGolems.h"
#include "../include/Units/UIceMages.h"
#include "../include/Units/UIllusionists.h"
#include "../include/Units/UMagicFamiliars.h"
#include "../include/Units/UNorthernMonks.h"
#include "../include/Units/UPeasants.h"
#include "../include/Units/URedCapeMonks.h"
#include "../include/Units/USavageMonks.h"
#include "../include/Units/UScouts.h"
#include "../include/Units/UShockTroops.h"
#include "../include/Units/USorcerers.h"
#include "../include/Units/UThugs.h"
#include "../include/Units/UUtemCrossbowmen.h"
#include "../include/Units/UUtemGuardsmen.h"
#include "../include/Units/UUtemSwordsmen.h"

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

//Resets the Game
void Game::reset(){
  if(state.m != NULL)
    delete state.m;

  state.m = new Map();
  state.m->revealTile(1);
  state.m->revealTile(2);

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

  int specialColorCount;
  do{
    specialColorCount = 0;
    for(int i = 0; i < N_DICE_IN_SOURCE; i++){
      this->rollSourceDie(i);
      if(state.sourceDice[i] == BLACK || state.sourceDice[i] == GOLD)
        specialColorCount++;
    }
  } while(specialColorCount > N_DICE_IN_SOURCE - specialColorCount);

  state.diceTaken = false;
  state.isDayNight = true;
  state.gameOver = false;

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

  state.RegularUnitsDeck.push_back(new UForesters());
  state.RegularUnitsDeck.push_back(new UForesters());
  state.RegularUnitsDeck.push_back(new UGuardianGolems());
  state.RegularUnitsDeck.push_back(new UGuardianGolems());
  state.RegularUnitsDeck.push_back(new UUtemGuardsmen());
  state.RegularUnitsDeck.push_back(new UUtemGuardsmen());
  state.RegularUnitsDeck.push_back(new UUtemCrossbowmen());
  state.RegularUnitsDeck.push_back(new UUtemCrossbowmen());
  state.RegularUnitsDeck.push_back(new UUtemSwordsmen());
  state.RegularUnitsDeck.push_back(new UUtemSwordsmen());
  state.RegularUnitsDeck.push_back(new UScouts());
  state.RegularUnitsDeck.push_back(new UScouts());
  state.RegularUnitsDeck.push_back(new UShockTroops());
  state.RegularUnitsDeck.push_back(new UShockTroops());
  state.RegularUnitsDeck.push_back(new UIllusionists());
  state.RegularUnitsDeck.push_back(new UIllusionists());
  state.RegularUnitsDeck.push_back(new UHerbalists());
  state.RegularUnitsDeck.push_back(new UHerbalists());
  state.RegularUnitsDeck.push_back(new URedCapeMonks());
  state.RegularUnitsDeck.push_back(new UNorthernMonks());
  state.RegularUnitsDeck.push_back(new USavageMonks());
  state.RegularUnitsDeck.push_back(new UMagicFamiliars());
  state.RegularUnitsDeck.push_back(new UMagicFamiliars());
  state.RegularUnitsDeck.push_back(new UThugs());
  state.RegularUnitsDeck.push_back(new UThugs());
  state.RegularUnitsDeck.push_back(new UPeasants());
  state.RegularUnitsDeck.push_back(new UPeasants());
  state.RegularUnitsDeck.push_back(new UPeasants());

  state.EliteUnitsDeck.push_back(new UAltemGuardians());
  state.EliteUnitsDeck.push_back(new UAltemGuardians());
  state.EliteUnitsDeck.push_back(new UAltemGuardians());
  state.EliteUnitsDeck.push_back(new UAltemMages());
  state.EliteUnitsDeck.push_back(new UAltemMages());
  state.EliteUnitsDeck.push_back(new UAmotepGunners());
  state.EliteUnitsDeck.push_back(new UAmotepGunners());
  state.EliteUnitsDeck.push_back(new UAmotepFreezers());
  state.EliteUnitsDeck.push_back(new UAmotepFreezers());
  state.EliteUnitsDeck.push_back(new UCatapults());
  state.EliteUnitsDeck.push_back(new UCatapults());
  state.EliteUnitsDeck.push_back(new UCatapults());
  state.EliteUnitsDeck.push_back(new UDelphanaMasters());
  state.EliteUnitsDeck.push_back(new UDelphanaMasters());
  state.EliteUnitsDeck.push_back(new UIceMages());
  state.EliteUnitsDeck.push_back(new UIceMages());
  state.EliteUnitsDeck.push_back(new UIceGolems());
  state.EliteUnitsDeck.push_back(new UIceGolems());
  state.EliteUnitsDeck.push_back(new UFireMages());
  state.EliteUnitsDeck.push_back(new UFireMages());
  state.EliteUnitsDeck.push_back(new UFireGolems());
  state.EliteUnitsDeck.push_back(new UFireGolems());
  state.EliteUnitsDeck.push_back(new USorcerers());
  state.EliteUnitsDeck.push_back(new USorcerers());
  state.EliteUnitsDeck.push_back(new UHeroesBlue());
  state.EliteUnitsDeck.push_back(new UHeroesGreen());
  state.EliteUnitsDeck.push_back(new UHeroesRed());
  state.EliteUnitsDeck.push_back(new UHeroesWhite());
  this->shuffleUnits();

  for(int i = 0; i < N_UNITS_IN_OFFER; i++){
    state.UnitOffer.push_back(state.RegularUnitsDeck[state.RegularUnitsDeck.size()-1]);
    state.RegularUnitsDeck.erase(state.RegularUnitsDeck.end() - 1);
  }

  for(int i = 0; i < state.handMaxSize; i++)
    state.hand.push_back(state.playerDeedDeck.drawCard());
}

//Shuffle the Regular and Elite Units Deck
void Game::shuffleUnits(){
  const int swaps = 500;
  int p1, p2;
  Unit* aux;

  for(int i = 0; i < swaps; i++){
    p1 = rand()%(state.RegularUnitsDeck.size());
    p2 = rand()%(state.RegularUnitsDeck.size());
    aux = state.RegularUnitsDeck[p1];
    state.RegularUnitsDeck[p1] = state.RegularUnitsDeck[p2];
    state.RegularUnitsDeck[p2] = aux;

    p1 = rand()%(state.EliteUnitsDeck.size());
    p2 = rand()%(state.EliteUnitsDeck.size());
    aux = state.EliteUnitsDeck[p1];
    state.EliteUnitsDeck[p1] = state.EliteUnitsDeck[p2];
    state.EliteUnitsDeck[p2] = aux;
  }
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
    case USE_CARD_SIDEWAYS:
      stepUseCardSideways(actionParam);
      break;
    case TAKE_DIE_FROM_SOURCE:
      stepTakeDieFromSource(actionParam);
      break;
    case MOVE_TO_ADJACENT_HEX:
      stepMoveToHex(actionParam);
      break;
    case REVEAL_ADJEACENT_TILE:
      stepRevealTile(actionParam);
      break;
    case RECRUIT_UNIT:
      stepRecruitUnit(actionParam);
      break;
    case END_TURN:
      stepEndTurn(actionParam);
      break;
    case USE_UNIT:
      stepUseUnit(actionParam);
      break;
    case QUIT_GAME:
      state.gameOver = true;
      break;
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

  printf("Cards in Deed Deck: %02d               Units:", state.playerDeedDeck.getSize());
  for(int i = 0; i < state.PlayerUnits.size(); i++)
    printf(" %s", state.PlayerUnits[i]->getName().c_str());

  printf("\nCards in Discard Pile: %02d            Units in offer:", state.playerDiscardDeck.getSize());
  for(int i = 0; i < state.UnitOffer.size(); i++)
    printf(" %s", state.UnitOffer[i]->getName().c_str());

  printf("\nCurrent Round: %d", state.currentRound);

  //Fame
  printf("\nFame: %d\nReputation: %d\n\n", state.exp, state.reputation);

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

void Game::stepUseCardSideways(int actionParam){
  if(actionParam < 0 || actionParam > state.hand.size() || state.hand[actionParam]->getCardType() == WOUND)
    return;

  std::vector<std::string> choices;
	choices.push_back("Attack 1");
	choices.push_back("Block 1");
	choices.push_back("Move 1");
	choices.push_back("Influence 1");

  switch(state.player->chooseOption(choices)){
    case 0:
      state.avAttack++;
      break;
    case 1:
      state.avBlock++;
      break;
    case 2:
      state.avMove++;
      break;
    case 3:
      state.avInfluence++;
      break;
  }

  state.playerDiscardDeck.addCardTop(state.hand[actionParam]);
  state.hand.erase(state.hand.begin() + actionParam);
}

void Game::stepUseUnit(int actionParam){
  if(actionParam < 0 || actionParam >= state.PlayerUnits.size())
    return;

  if(state.PlayerUnits[actionParam]->isReady()){
    state.PlayerUnits[actionParam]->playEffect(&state);
    state.PlayerUnits[actionParam]->setReady(false);
  }
}

void Game::stepMoveToHex(int actionParam){
  if(actionParam < 0 || actionParam > 6)
    return;

  HEX *next = state.curHex->neighboors[actionParam];
  int moveCost;

  static const short int refTableHex[7][6] = {{5, 6, 4, 1, 2, 3},
                                              {6, 2, 0, 5, 3, 4},
                                              {4, 0, 6, 3, 1, 5},
                                              {0, 1, 2, 4, 5, 6},
                                              {1, 5, 3, 0, 6, 2},
                                              {2, 3, 1, 6, 4, 0},
                                              {3, 4, 5, 2, 0, 1}};

  static const short int refTableTile[NUM_TILES][7][6] = {{{ 2, 2,-1, 0, 0, 0}, { 2, 1, 0, 1, 0, 0}, {-1, 0,-1, 0,-1, 0}, { 0, 0, 0, 0, 0, 0}, { 0, 1, 0,-1, 0,-1}, { 0, 0,-1, 0,-1,-1}, { 0, 0, 0,-1,-1,-1}},
                                                          {{ 4, 4, 2, 1, 1, 1}, { 4, 3, 1, 3, 1 ,1}, { 2, 1, 2, 1, 0, 1}, { 1, 1, 1, 1, 1, 1}, { 1, 3, 1,-1, 1,-1}, { 1, 1, 0, 1, 0,-1}, { 1, 1, 1,-1,-1,-1}},
                                                          {{ 5, 5,-1, 2, 2, 2}, { 5, 4, 2, 4, 2, 2}, {-1, 2,-1, 2,-1, 2}, { 2, 2, 2, 2, 2, 2}, { 2, 4, 2, 1, 2, 1}, { 2, 2,-1, 2,-1, 0}, { 2, 2, 2, 1, 0, 0}},
                                                          {{ 7, 7, 4, 3, 3, 3}, { 7, 6, 3, 6, 3, 3}, { 4, 3, 4, 3, 1, 3}, { 3, 3, 3, 3, 3, 3}, { 3, 6, 3,-1, 3,-1}, { 3, 3, 1, 3, 1,-1}, { 3, 3, 3,-1,-1,-1}},
                                                          {{ 8, 8, 5, 4, 4, 4}, { 8, 7, 4, 7, 4, 4}, { 5, 4, 5, 4, 2, 4}, { 4, 4, 4, 4, 4, 4}, { 4, 7, 4, 3, 4, 3}, { 4, 4, 2, 4, 2, 1}, { 4, 4, 4, 3, 1, 1}},
                                                          {{ 9, 9,-1, 5, 5, 5}, { 9, 8, 5, 8, 5, 5}, {-1, 5,-1, 5,-1, 5}, { 5, 5, 5, 5, 5, 5}, { 5, 8, 5, 4, 5, 4}, { 5, 5,-1, 5,-1, 2}, { 5, 5, 5, 4, 2, 2}},
                                                          {{11,11, 7, 6, 6, 6}, {11,10, 6,10, 6, 6}, { 7, 6, 7, 6, 3, 6}, { 6, 6, 6, 6, 6, 6}, { 6,10, 6,-1, 6,-1}, { 6, 6, 3, 6, 3,-1}, { 6, 6, 6,-1,-1,-1}},
                                                          {{12,12, 8, 7, 7, 7}, {12,11, 7,11, 7, 7}, { 8, 7, 8, 7, 4, 7}, { 7, 7, 7, 7, 7, 7}, { 7,11, 7, 6, 7, 6}, { 7, 7, 4, 7, 4, 3}, { 7, 7, 7, 6, 3, 3}},
                                                          {{13,13, 9, 8, 8, 8}, {13,12, 8,12, 8, 8}, { 9, 8, 9, 8, 5, 8}, { 8, 8, 8, 8, 8, 8}, { 8,12, 8, 7, 8, 7}, { 8, 8, 5, 8, 5, 4}, { 8, 8, 8, 7, 4, 4}},
                                                          {{14,14,-1, 9, 9, 9}, {14,13, 9,13, 9, 9}, {-1, 9,-1, 9,-1, 9}, { 9, 9, 9, 9, 9, 9}, { 9,13, 9, 8, 9, 8}, { 9, 9,-1, 9,-1, 5}, { 9, 9, 9, 8, 5, 5}},
                                                          {{-1,-1,11,10,10,10}, {-1,-1,10,-1,10,10}, {11,10,11,10, 6,10}, {10,10,10,10,10,10}, {10,-1,10,-1,10,-1}, {10,10, 6,10, 6,-1}, {10,10,10,-1,-1,-1}},
                                                          {{-1,-1,12,11,11,11}, {-1,-1,11,-1,11,11}, {12,11,12,11, 7,11}, {11,11,11,11,11,11}, {11,-1,11,10,11,10}, {11,11, 7,11, 7, 6}, {11,11,11,10, 6, 6}},
                                                          {{-1,-1,13,12,12,12}, {-1,-1,12,-1,12,12}, {13,12,13,12, 8,12}, {12,12,12,12,12,12}, {12,-1,12,11,12,11}, {12,12, 8,12, 8, 8}, {12,12,12,11, 7, 7}},
                                                          {{-1,-1,14,13,13,13}, {-1,-1,13,-1,13,13}, {14,13,14,13, 9,13}, {13,13,13,13,13,13}, {13,-1,13,12,13,12}, {13,13, 9,13, 9, 7}, {13,13,13,12, 8, 8}},
                                                          {{-1,-1,-1,14,14,14}, {-1,-1,14,-1,14,14}, {-1,14,-1,14,-1,14}, {14,14,14,14,14,14}, {14,-1,14,13,14,13}, {14,14,-1,14,-1, 9}, {14,14,14,13, 9, 9}}};

  if(next != NULL && next->terrain != NONET){
    moveCost = state.m->getMoveCost(*next, state.isDayNight);
    if(state.avMove >= moveCost){
      state.avMove = state.avMove - moveCost;
      state.curHex = next;

      state.curTileN = refTableTile[state.curTileN][state.curHexN][actionParam];
      state.curHexN = refTableHex[state.curHexN][actionParam];
    }
  }
}

void Game::stepRevealTile(int actionParam){
  if(actionParam != 0 && actionParam != 1 || state.avMove < 2) //0 - Up, 1 - Down
    return;

  bool result;

  static const short int refMatrix[NUM_TILES][7][2] = {{{ 2,-1}, { 2, 1}, {-1,-1}, {-1,-1}, { 1,-1}, {-1,-1}, {-1,-1}},
                                                       {{ 4, 2}, { 4, 3}, { 2, 0}, {-1,-1}, { 3,-1}, { 0,-1}, {-1,-1}},
                                                       {{ 5,-1}, { 5, 4}, {-1,-1}, {-1,-1}, { 4, 1}, { 0,-1}, { 1, 0}},
                                                       {{ 7, 4}, { 7, 6}, { 4, 1}, {-1,-1}, { 6,-1}, { 1,-1}, {-1,-1}},
                                                       {{ 8, 5}, { 8, 7}, { 5, 2}, {-1,-1}, { 7, 3}, { 2, 1}, { 3, 1}},
                                                       {{ 9,-1}, { 9, 8}, {-1,-1}, {-1,-1}, { 8, 4}, { 1,-1}, { 4, 1}},
                                                       {{11, 7}, {11,10}, { 7, 3}, {-1,-1}, {10,-1}, { 3,-1}, {-1,-1}},
                                                       {{12, 8}, {12,11}, { 8, 4}, {-1,-1}, {11, 6}, { 4, 3}, { 6, 3}},
                                                       {{13, 9}, {13,12}, { 9, 5}, {-1,-1}, {12, 7}, { 5, 4}, { 7, 4}},
                                                       {{14,-1}, {14,13}, {-1,-1}, {-1,-1}, {14, 8}, { 5,-1}, { 7, 5}},
                                                       {{11,-1}, {-1,-1}, {11, 6}, {-1,-1}, {-1,-1}, { 6,-1}, {-1,-1}},
                                                       {{12,-1}, {-1,-1}, {12, 7}, {-1,-1}, {10,-1}, { 7, 6}, {10, 6}},
                                                       {{13,-1}, {-1,-1}, {13, 8}, {-1,-1}, {11,-1}, { 8, 7}, {11, 7}},
                                                       {{14,-1}, {-1,-1}, {14, 9}, {-1,-1}, {12,-1}, { 9, 8}, {12, 8}},
                                                       {{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {13,-1}, { 9,-1}, {13, 9}}};

  result = state.m->revealTile(refMatrix[state.curTileN][state.curHexN][actionParam]);

  if(result)
    state.avMove = state.avMove - 2;
}

void Game::stepTakeDieFromSource(int actionParam){
  if(actionParam >= N_DICE_IN_SOURCE || (state.diceTaken && !state.ManaDrawWeakActive))
    return;

  std::vector<std::string> choices;
	choices.push_back("Red");
	choices.push_back("Blue");
	choices.push_back("Green");
	choices.push_back("White");

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
        switch (state.player->chooseOption(choices)) {
          case 0:
            state.playerTokensRed++;
            break;
          case 1:
            state.playerTokensBlue++;
            break;
          case 2:
            state.playerTokensGreen++;
            break;
          case 3:
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

void Game::stepRecruitUnit(int actionParam){
  if(actionParam < 0 || actionParam >= state.UnitOffer.size())
    return;

  state.UnitOffer[actionParam]->tryToRecruit(&state);
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
