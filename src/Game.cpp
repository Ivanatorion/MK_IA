#include <cstdio>
#include <cstdlib>

#include "../include/Game.h"

//Units
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

//Basic Action Cards
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

//Advanced Action cards
#include "../include/Cards/ActionCards/Advanced/ACFireBolt.h"
#include "../include/Cards/ActionCards/Advanced/ACIceBolt.h"
#include "../include/Cards/ActionCards/Advanced/ACSwiftBolt.h"
#include "../include/Cards/ActionCards/Advanced/ACCrushingBolt.h"
#include "../include/Cards/ActionCards/Advanced/ACBloodRage.h"
#include "../include/Cards/ActionCards/Advanced/ACIceShield.h"
#include "../include/Cards/ActionCards/Advanced/ACAgility.h"
#include "../include/Cards/ActionCards/Advanced/ACRefreshingWalk.h"
#include "../include/Cards/ActionCards/Advanced/ACIntimidate.h"
#include "../include/Cards/ActionCards/Advanced/ACFrostBridge.h"
#include "../include/Cards/ActionCards/Advanced/ACSongOfWind.h"
#include "../include/Cards/ActionCards/Advanced/ACPathFinding.h"

#include "../include/Cards/Wound.h"

//Skills
#include "../include/Skills/Tovak/ColdSwordsmanship.h"
#include "../include/Skills/Tovak/DoubleTime.h"
#include "../include/Skills/Tovak/IDontGiveADamn.h"
#include "../include/Skills/Tovak/IFeelNoPain.h"
#include "../include/Skills/Tovak/ManaOverload.h"
#include "../include/Skills/Tovak/NightSharpshooting.h"
#include "../include/Skills/Tovak/ResistanceBreak.h"
#include "../include/Skills/Tovak/ShieldMastery.h"
#include "../include/Skills/Tovak/TvkMotivation.h"
#include "../include/Skills/Tovak/WhoNeedsMagic.h"

Game::Game(Player *player, UserInterface *ui){
  this->state.player = player;
  this->userinterface = ui;
  state.m = NULL;
  state.gameRunning = false;
}

//Advances the Game to the next Round
void Game::resetRound(){

  //Updates Round number and Day/Night
  state.currentRound++;
  state.isDayNight = (state.currentRound%2 == 1);

  //Ensures Game Scene is MoveAndExplore
  state.gameScene = MOVE_AND_EXPLORE;

  //Re-roll the dice in the Source.
  int specialColorCount;
  do{
    specialColorCount = 0;
    for(int i = 0; i < N_DICE_IN_SOURCE; i++){
      this->rollSourceDie(i);
      if(state.sourceDice[i] == BLACK || state.sourceDice[i] == GOLD)
        specialColorCount++;
    }
  } while(specialColorCount > N_DICE_IN_SOURCE - specialColorCount);

  //Refresh the Unit Offer.
  for(int i = 0; i < state.UnitOffer.size(); i++)
    delete state.UnitOffer[i];
  state.UnitOffer.clear();
  for(int i = 0; i < N_UNITS_IN_OFFER; i++){
    if(i % 2 == 0 && state.m->isCoreTileRevealed()){
      if(state.EliteUnitsDeck.size() > 0){
        state.UnitOffer.push_back(state.EliteUnitsDeck[state.EliteUnitsDeck.size()-1]);
        state.EliteUnitsDeck.erase(state.EliteUnitsDeck.end() - 1);
      }
    }
    else{
      if(state.RegularUnitsDeck.size() > 0){
        state.UnitOffer.push_back(state.RegularUnitsDeck[state.RegularUnitsDeck.size()-1]);
        state.RegularUnitsDeck.erase(state.RegularUnitsDeck.end() - 1);
      }
    }
  }

  //Refresh the Advanced Action Offer
  if(state.advancedActionsOffer[2] != NULL){
    delete state.advancedActionsOffer[2];
    state.advancedActionsOffer[2] = NULL;
  }
  state.advancedActionsOffer[2] = state.advancedActionsOffer[1];
  state.advancedActionsOffer[1] = state.advancedActionsOffer[0];
  if(!state.advancedActionsDeck.isEmpty())
    state.advancedActionsOffer[0] = state.advancedActionsDeck.drawCard();
  else
    state.advancedActionsOffer[0] = NULL;

  //Shuffles the Player Deed Deck and draw up to its hand maximum size.
  while(!state.playerDiscardDeck.isEmpty())
    state.playerDeedDeck.addCardTop(state.playerDiscardDeck.drawCard());
  while(state.playerHand.size() > 0){
    state.playerDeedDeck.addCardTop(state.playerHand[0]);
    state.playerHand.erase(state.playerHand.begin());
  }
  state.playerDeedDeck.shuffle();
  for(int i = 0; i < state.playerHandMaxSize; i++)
    state.playerHand.push_back(state.playerDeedDeck.drawCard());
}

//Resets the Game
void Game::resetGame(){

  //Initialize the Map
  if(state.m != NULL)
    delete state.m;
  state.m = new Map();
  state.m->revealTile(1);
  state.m->revealTile(2);

  state.rampagingHexAttacked = NULL;
  state.assaultingSite = false;
  state.spellsToGain = 0;

  state.currentRound = 0;

  //Player Attributes
  state.playerFame = 0;
  state.playerReputation = 0;
  state.playerHandMaxSize = 5;
  state.playerHandSizeBonus = 0;
  state.playerArmor = 2;
  state.playerLevel = 1;
  state.playerCommandTokens = 1;
  state.playerKeepsConquered = 0;

  state.curTileN = 0;
  state.curHexN = 3;
  state.curTile = 0;
  state.curHex = state.m->getTile(0).hexes[3];

  clearStateAvs();

  //Decks and Offers
  state.advancedActionsOffer[0] = NULL;
  state.advancedActionsOffer[1] = NULL;
  state.advancedActionsOffer[2] = NULL;
  state.spellOffer[0] = NULL;
  state.spellOffer[1] = NULL;
  state.spellOffer[2] = NULL;

  state.advancedActionsDeck.clear();
  state.artifactsDeck.clear();
  state.spellsDeck.clear();

  state.advancedActionsDeck.addCardTop(new ACFireBolt());
  state.advancedActionsDeck.addCardTop(new ACIceBolt());
  state.advancedActionsDeck.addCardTop(new ACSwiftBolt());
  state.advancedActionsDeck.addCardTop(new ACCrushingBolt());
  state.advancedActionsDeck.addCardTop(new ACBloodRage());
  state.advancedActionsDeck.addCardTop(new ACIceShield());
  state.advancedActionsDeck.addCardTop(new ACAgility());
  state.advancedActionsDeck.addCardTop(new ACRefreshingWalk());
  state.advancedActionsDeck.addCardTop(new ACIntimidate());
  state.advancedActionsDeck.addCardTop(new ACFrostBridge());
  state.advancedActionsDeck.addCardTop(new ACSongOfWind());
  state.advancedActionsDeck.addCardTop(new ACPathFinding());
  state.advancedActionsDeck.shuffle();

  state.advancedActionsOffer[2] = state.advancedActionsDeck.drawCard();
  state.advancedActionsOffer[1] = state.advancedActionsDeck.drawCard();
  state.advancedActionsOffer[0] = state.advancedActionsDeck.drawCard();

  //Skills
  state.SkillsObtained.clear();
  state.SkillsNotObtained.clear();

  state.SkillsNotObtained.push_back(new ColdSwordsmanship());
  state.SkillsNotObtained.push_back(new DoubleTime());
  state.SkillsNotObtained.push_back(new IDontGiveADamn());
  state.SkillsNotObtained.push_back(new IFeelNoPain());
  state.SkillsNotObtained.push_back(new ManaOverload());
  state.SkillsNotObtained.push_back(new NightSharpshooting());
  state.SkillsNotObtained.push_back(new ResistanceBreak());
  state.SkillsNotObtained.push_back(new ShieldMastery());
  state.SkillsNotObtained.push_back(new TvkMotivation());
  state.SkillsNotObtained.push_back(new WhoNeedsMagic());
  this->shuffleSkills();

  state.BattleEnemies.clear();
  state.BattleEnemiesSelected.clear();
  state.BattleAttacksToAssign.clear();

  //Units
  state.RegularUnitsDeck.clear();
  state.EliteUnitsDeck.clear();
  state.PlayerUnits.clear();
  state.UnitOffer.clear();

  state.playerDiscardDeck.clear();
  state.playerDeedDeck.clear();

  //Mana Tokens and Crystals
  state.playerTokensRed = 0;
  state.playerTokensWhite = 0;
  state.playerTokensGreen = 0;
  state.playerTokensBlue = 0;
  state.playerCrystalsRed = 0;
  state.playerCrystalsWhite = 0;
  state.playerCrystalsGreen = 0;
  state.playerCrystalsBlue = 0;

  clearSpecialEffects();

  state.fameToGain = 0;
  state.repToGain = 0;

  state.diceTaken = false;
  state.gameOver = false;

  //Starting Cards
  state.playerDeedDeck.addCardTop(new ACCrystallize());
  state.playerDeedDeck.addCardTop(new ACInstinct());
  state.playerDeedDeck.addCardTop(new ACColdToughness());
  state.playerDeedDeck.addCardTop(new ACManaDraw());
  state.playerDeedDeck.addCardTop(new ACConcentration());
  state.playerDeedDeck.addCardTop(new ACMarch());
  state.playerDeedDeck.addCardTop(new ACMarch());
  state.playerDeedDeck.addCardTop(new ACPromise());
  state.playerDeedDeck.addCardTop(new ACRage());
  state.playerDeedDeck.addCardTop(new ACRage());
  state.playerDeedDeck.addCardTop(new ACThreaten());
  state.playerDeedDeck.addCardTop(new ACStamina());
  state.playerDeedDeck.addCardTop(new ACStamina());
  state.playerDeedDeck.addCardTop(new ACSwiftness());
  state.playerDeedDeck.addCardTop(new ACSwiftness());
  state.playerDeedDeck.addCardTop(new ACTranquility());

  //Unit Decks
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

  this->resetRound();
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

//Shuffle the Skills
void Game::shuffleSkills(){
  const int swaps = 500;
  int p1, p2;
  Skill* aux;

  for(int i = 0; i < swaps; i++){
      p1 = rand()%(state.SkillsNotObtained.size());
      p2 = rand()%(state.SkillsNotObtained.size());
      aux = state.SkillsNotObtained[p1];
      state.SkillsNotObtained[p1] = state.SkillsNotObtained[p2];
      state.SkillsNotObtained[p2] = aux;
  }
}

//Rolls a die in the Source
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

//The "step" function makes the game "state" transition based on input "action/actionParam"
/*
  The "actionParam" gives aditional information on how to execute the action. This information is, for each action:

  NOTHING = Unused
  USE_CARD_WEAK = Which card in the Player hand should be played
  USE_CARD_STRONG = Which card in the Player hand should be played
  USE_CARD_SIDEWAYS = Which card in the Player hand should be played
  USE_UNIT = Which Player Unit should be used
  MOVE_TO_ADJACENT_HEX = Which adjacent HEX should the Player move (0 being TOPLEFT, increasing clockwise)
  TAKE_DIE_FROM_SOURCE = Which die the Player will take
  RECRUIT_UNIT = Which Unit (position in UnitOffer) the Player will recruit
  REVEAL_ADJEACENT_TILE = 0 if revealing "Upmost" Tile, 1 if revealing "Downmost" TILE
  ATTACK_RAMPAGING_ENEMY = Which adjacent HEX the Enemy is (0 being TOPLEFT, increasing clockwise)
  SELECT_ENEMY = Which Enemy to be selected
  ATTACK_SELECTED_ENEMIES = Unused
  BLOCK_ENEMY_IN_BATTLE = Which Enemy from the BattleEnemies vector the Player will attack
  ADVANCE_BATTLE_PHASE = Unused
  END_TURN = Unused
  QUIT_GAME = Unused
*/
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
    case ATTACK_RAMPAGING_ENEMY:
      stepAttackRampagingEnemy(actionParam);
      break;
    case SELECT_ENEMY:
      stepSelectEnemy(actionParam);
      break;
    case SELECT_ATTACK_TO_ASSING:
      stepSelectAttackToAssign(actionParam);
      break;
    case ATTACK_SELECTED_ENEMIES:
      stepAttackSelectedEnemies(actionParam);
      break;
    case ADVANCE_BATTLE_PHASE:
      stepAdvanceBattlePhase(actionParam);
      break;
    case BLOCK_ENEMY:
      stepBlockEnemy(actionParam);
      break;
    case ASSING_DAMAGE_TO_UNIT:
      stepAssingDamageUnit(actionParam);
      break;
    case ASSING_DAMAGE_TO_PLAYER:
      stepAssingDamagePlayer(actionParam);
      break;
    case END_TURN:
      stepEndTurn(actionParam);
      break;
    case USE_UNIT:
      stepUseUnit(actionParam);
      break;
    case USE_SKILL:
      stepUseSkill(actionParam);
      break;
    case HEAL_PLAYER_WOUND:
      stepHealPlayer(actionParam);
      break;
    case QUIT_GAME:
      state.gameOver = true;
      break;
  }
}

//Runs the game main loop
void Game::run(){
  ACTION nextAction;
  int nextParam;

  this->resetGame();
  state.gameRunning = true;

  while(!this->state.gameOver){
      this->userinterface->printState(state);
      this->state.player->takeAction(state, &nextAction, &nextParam);
      this->step(nextAction, nextParam);
  }

  state.gameRunning = false;
}

void Game::stepUseCardWeak(int actionParam){
  bool hasMana = false;
  Card *aux;

  //Check if choosen Card is valid
  if(actionParam < state.playerHand.size())
    aux = state.playerHand[actionParam];
  else
    return;

  //Cant play Wounds
  if(aux->getCardType() == WOUND)
    return;

  //Checks if the player has mana
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

  //Discard the Card and Play its effect
  state.playerDiscardDeck.addCardTop(aux);
  state.playerHand.erase(state.playerHand.begin() + actionParam);
  aux->playCardWeak(&state);
}

void Game::stepUseCardStrong(int actionParam){
  bool hasMana = false;
  Card *aux;

  //Check if choosen Card is valid
  if(actionParam < state.playerHand.size())
    aux = state.playerHand[actionParam];
  else
    return;

  //Cant play Wounds
  if(aux->getCardType() == WOUND)
    return;

  //Checks if the player has mana
  if(aux->getCardType() == ARTIFACTCARD)
    hasMana = true;
  else{
    if(aux->getCardType() == ACTIONCARD){
      if(state.ConcentrationStrong){
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

  //Discard the Card and Play its effect
  state.playerDiscardDeck.addCardTop(aux);
  state.playerHand.erase(state.playerHand.begin() + actionParam);

  //Check if used Concentration
  if(state.ConcentrationStrong){
    aux->playCardStrong(&state);
    state.ConcentrationStrong = false;
  }
  else{
    aux->playCardStrong(&state);
  }

}

void Game::stepUseCardSideways(int actionParam){
  if(actionParam < 0 || actionParam > state.playerHand.size() || state.playerHand[actionParam]->getCardType() == WOUND)
    return;

  int statusAmmount;

  std::vector<std::string> choices;

  if(state.TovakIDontGiveADamn){
    if(state.playerHand[actionParam]->isBasic()){
      choices.push_back("Attack 2");
    	choices.push_back("Block 2");
    	choices.push_back("Move 2");
    	choices.push_back("Influence 2");
      statusAmmount = 2;
    }
    else{
      choices.push_back("Attack 3");
    	choices.push_back("Block 3");
    	choices.push_back("Move 3");
    	choices.push_back("Influence 3");
      statusAmmount = 3;
    }
  }
  else{
    choices.push_back("Attack 1");
  	choices.push_back("Block 1");
  	choices.push_back("Move 1");
  	choices.push_back("Influence 1");
    statusAmmount = 1;
  }

  switch(state.player->chooseOption(choices)){
    case 0:
      state.avAttack = state.avAttack + statusAmmount;
      break;
    case 1:
      state.avBlock = state.avBlock + statusAmmount;
      break;
    case 2:
      state.avMove = state.avMove + statusAmmount;

      if(state.gameScene == BATTLE_RANGED && state.AgilityStrong){
    		state.avRangedAttack = state.avRangedAttack + state.avMove/2;
    		state.avMove = state.avMove%2;
    	}

    	if(state.gameScene == BATTLE_ATTACK && (state.AgilityWeak || state.AgilityStrong)){
    		state.avAttack = state.avAttack + state.avMove/2;
    		state.avMove = state.avMove%2;
    	}

      break;
    case 3:
      state.avInfluence = state.avInfluence + statusAmmount;
      break;
  }

  state.playerDiscardDeck.addCardTop(state.playerHand[actionParam]);
  state.playerHand.erase(state.playerHand.begin() + actionParam);

  state.TovakIDontGiveADamn = false;
}

void Game::stepUseUnit(int actionParam){
  if(actionParam < 0 || actionParam >= state.PlayerUnits.size())
    return;

  if(state.PlayerUnits[actionParam]->isReady()){
    state.PlayerUnits[actionParam]->playEffect(&state);
    state.PlayerUnits[actionParam]->setReady(false);
  }
}

void Game::stepUseSkill(int actionParam){
  if(actionParam < 0 || actionParam >= state.SkillsObtained.size())
    return;

  if(!state.SkillsObtained[actionParam]->isOnCooldown()){
    state.SkillsObtained[actionParam]->onPlayed(&state);
    state.SkillsObtained[actionParam]->setOnCooldown(true);
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

    //FrostBridge
    if(state.FrostBridgeWeak && next->terrain == SWAMP)
      moveCost = 1;
    if(state.FrostBridgeStrong && (next->terrain == SWAMP || next->terrain == LAKE))
      moveCost = 1;

    //PathFinding
    if(state.PathFindingWeak){
      moveCost = moveCost - 1;
      if(moveCost < 2)
        moveCost = 2;
    }
    if(state.PathFindingStrong){
      if(moveCost < 50) moveCost = 2;
    }

    //SongOfWind
    if(state.SongOfWindWeak && (next->terrain == PLAIN || next->terrain == DESERT || next->terrain == WASTELAND)){
      moveCost = moveCost - 1;
      if(moveCost < 0)
        moveCost = 0;
    }
    if(state.SongOfWindStrong && (next->terrain == PLAIN || next->terrain == DESERT || next->terrain == WASTELAND)){
      moveCost = moveCost - 2;
      if(moveCost < 0)
        moveCost = 0;
    }
    if(state.SongOfWindStrongBlue && next->terrain == LAKE){
      moveCost = 0;
    }

    if(state.avMove >= moveCost){
      state.avMove = state.avMove - moveCost;
      state.curHex = next;

      state.curTileN = refTableTile[state.curTileN][state.curHexN][actionParam];
      state.curHexN = refTableHex[state.curHexN][actionParam];

      //Check if revealed garisons
      if(state.isDayNight){
        for(int i = 0; i < 6; i++){
          if(state.curHex->neighboors[i] != NULL){
            if(state.curHex->neighboors[i]->faceDownEnemyToken != NONEE){
              state.curHex->neighboors[i]->faceUpEnemyToken = state.m->getEnemy(state.curHex->neighboors[i]->faceDownEnemyToken);
              state.curHex->neighboors[i]->faceDownEnemyToken = NONEE;
            }
          }
        }
      }

      //Check if assaulting
      if((state.curHex->location == KEEP || state.curHex->location == TOWER) && (state.curHex->faceUpEnemyToken.enemyType != NONEE || state.curHex->faceDownEnemyToken != NONEE)){
        if(state.playerReputation > -7) state.playerReputation--;

        state.gameScene = BATTLE_RANGED;
        state.rampagingHexAttacked = NULL;
        state.assaultingSite = true;
        if(state.curHex->faceDownEnemyToken != NONEE){
          state.curHex->faceUpEnemyToken = state.m->getEnemy(state.curHex->faceDownEnemyToken);
          state.curHex->faceDownEnemyToken = NONEE;
        }
        state.BattleEnemies.push_back(state.curHex->faceUpEnemyToken);
        for(int i = 0; i < state.BattleEnemies.size(); i++){
          state.BattleEnemies[i].blocked = false;

          //Give enemies Fortification
          if(state.BattleEnemies[i].fortified)
            state.BattleEnemies[i].doubleFortified = true;
          else
            state.BattleEnemies[i].fortified = true;

          for(int j = 0; j < state.BattleEnemies[i].attacks.size(); j++){
            state.BattleEnemies[i].attacks[j].blocked = false;
          }
        }
      }

      //Check if adjacent to conquered Keep
      bool hasBonus = false;
      if(state.curHex->location == KEEP && state.curHex->hasShieldToken){
        state.playerHandSizeBonus = state.playerKeepsConquered;
        hasBonus = true;
      }
      for(int i = 0; i < 6; i++)
        if(state.curHex->neighboors[i]->location == KEEP && state.curHex->neighboors[i]->hasShieldToken){
          state.playerHandSizeBonus = state.playerKeepsConquered;
          hasBonus = true;
        }
      if(!hasBonus)
        state.playerHandSizeBonus = 0;

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
  if(actionParam >= N_DICE_IN_SOURCE || (state.diceTaken && !state.ManaDrawWeak))
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
    state.ManaDrawWeak = false;
  state.sourceDice[actionParam] = NONE;
}

void Game::stepRecruitUnit(int actionParam){
  if(actionParam < 0 || actionParam >= state.UnitOffer.size())
    return;

  if(state.playerCommandTokens > state.PlayerUnits.size())
    state.UnitOffer[actionParam]->tryToRecruit(&state);
}

void Game::stepEndTurn(int actionParam){
  state.diceTaken = false;
  state.gameScene = MOVE_AND_EXPLORE;

  //Clear all Mana Tokens
  state.playerTokensRed = 0;
  state.playerTokensBlue = 0;
  state.playerTokensGreen = 0;
  state.playerTokensWhite = 0;
  state.playerTokensBlack = 0;

  clearStateAvs();

  //Updates fame / reputation
  state.playerFame = state.playerFame + state.fameToGain;
  state.playerReputation = state.playerReputation + state.repToGain;
  state.fameToGain = 0;
  state.repToGain = 0;

  //Verifies if the player ended the turn on a mine, granting a Crystal
  checkEndedOnMine();

  //Verifies if a Level Up occured
  checkLevelUp();

  //Gain Spells
  while(state.spellsToGain > 0){
    gainSpell();
    state.spellsToGain--;
  }

  //Re-roll the dice in the Source
  for(int i = 0; i < N_DICE_IN_SOURCE; i++)
    if(state.sourceDice[i] == NONE)
      rollSourceDie(i);

  //Disable temporary effects
  clearSpecialEffects();

  //Refresh Skills
  for(int i = 0; i < state.SkillsObtained.size(); i++)
    if(state.SkillsObtained[i]->getCooldown() == ONCE_A_TURN)
      state.SkillsObtained[i]->setOnCooldown(false);

  //Draw Cards
  while(state.playerHand.size() < state.playerHandMaxSize + state.playerHandSizeBonus && !state.playerDeedDeck.isEmpty())
    state.playerHand.push_back(state.playerDeedDeck.drawCard());

  //Forces Round Reset
  if(state.playerHand.size() == 0 && state.playerDeedDeck.isEmpty())
    this->resetRound();

}

void Game::stepHealPlayer(int actionParam){
  if(state.gameScene == BATTLE_RANGED || state.gameScene == BATTLE_BLOCK || state.gameScene == BATTLE_ASSIGN || state.gameScene == BATTLE_ATTACK)
    return;

  if(state.avHeal == 0)
    return;

  for(int i = 0; i < state.playerHand.size(); i++){
    if(state.playerHand[i]->getCardType() == WOUND){
      delete state.playerHand[i];
      state.playerHand.erase(state.playerHand.begin() + i);
      state.avHeal--;
      return;
    }
  }

  if(state.playerDiscardDeck.removeWound()){
    state.avHeal--;
    return;
  }
}

void Game::checkEndedOnMine(){
  std::vector<std::string> choices;
  int choice = -1;

  switch(state.curHex->location){
    case MINEB:
      if(state.playerCrystalsBlue < 3) state.playerCrystalsBlue++;
      break;
    case MINEG:
      if(state.playerCrystalsGreen < 3) state.playerCrystalsGreen++;
      break;
    case MINER:
      if(state.playerCrystalsRed < 3) state.playerCrystalsRed++;
      break;
    case MINEW:
      if(state.playerCrystalsWhite < 3) state.playerCrystalsWhite++;
      break;
    case MINEBG:
      choices.push_back("Blue Crystal");
      choices.push_back("Green Crystal");
      choice = state.player->chooseOption(choices);
      break;
    case MINERW:
      choices.push_back("Red Crystal");
      choices.push_back("White Crystal");
      choice = state.player->chooseOption(choices) + 2;
      break;
    case MINEALL:
      choices.push_back("Blue Crystal");
      choices.push_back("Green Crystal");
      choices.push_back("Red Crystal");
      choices.push_back("White Crystal");
      choice = state.player->chooseOption(choices);
      break;
  }

  switch(choice) {
    case 0:
      if(state.playerCrystalsBlue < 3) state.playerCrystalsBlue++;
      break;
    case 1:
      if(state.playerCrystalsGreen < 3) state.playerCrystalsGreen++;
      break;
    case 2:
      if(state.playerCrystalsRed < 3) state.playerCrystalsRed++;
      break;
    case 4:
      if(state.playerCrystalsWhite < 3) state.playerCrystalsWhite++;
      break;
  }
}

void Game::checkLevelUp(){
  static const int maxFameOnLevel[9] = {2, 7, 14, 23, 34, 47, 62, 79, 98};
  static const int playerArmorOnLevel[10] = {2, 2, 3, 3, 3, 3, 4, 4, 4, 4};
  static const int playerHandSizeOnLevel[10] = {5, 5, 5, 5, 6, 6, 6, 6, 7, 7};
  bool levelUp = false;

  for(int i = 0; i < 9; i++){
    if(state.playerFame > maxFameOnLevel[i] && state.playerLevel < i + 2)
      levelUp = true;
  }

  if(levelUp){
    state.playerLevel++;
    if(state.playerLevel%2 == 1){
      state.playerCommandTokens++;
      state.playerArmor = playerArmorOnLevel[state.playerLevel - 1];
      state.playerHandMaxSize = playerHandSizeOnLevel[state.playerLevel - 1];
    }
    else{
      gainSkill();
      gainAdvancedAction();
    }
    checkLevelUp(); //Could have Leveled Up twice
  }
}

void Game::stepAttackRampagingEnemy(int actionParam){
  if(actionParam < 0 || actionParam > 6 || state.gameScene != MOVE_AND_EXPLORE)
    return;
  if(state.curHex->neighboors[actionParam]->location != ORC && state.curHex->neighboors[actionParam]->location != DRACONUM)
    return;

  state.gameScene = BATTLE_RANGED;
  state.rampagingHexAttacked = state.curHex->neighboors[actionParam];
  state.BattleEnemies.push_back(state.curHex->neighboors[actionParam]->faceUpEnemyToken);

  for(int i = 0; i < state.BattleEnemies.size(); i++){
    state.BattleEnemies[i].blocked = false;
    for(int j = 0; j < state.BattleEnemies[i].attacks.size(); j++){
      state.BattleEnemies[i].attacks[j].blocked = false;
    }
  }
}

//Battle
void Game::stepAttackSelectedEnemies(int actionParam){
  if(state.gameScene != BATTLE_RANGED && state.gameScene != BATTLE_ATTACK)
    return;

  bool fireRes = false, iceRes = false, physRes = false, coldFireRes = false;
  bool fort = false, doublefort = false;
  int totalHealth = 0;
  int totalAttack = 0;

  for(int i = 0; i < state.BattleEnemiesSelected.size(); i++){
    if(state.BattleEnemiesSelected[i].fRes)
      fireRes = true;
    if(state.BattleEnemiesSelected[i].iRes)
      iceRes = true;
    if(state.BattleEnemiesSelected[i].pRes)
      physRes = true;
    if(state.BattleEnemiesSelected[i].fRes && state.BattleEnemiesSelected[i].iRes)
      coldFireRes = true;

    if(state.BattleEnemiesSelected[i].fortified)
      fort = true;

    totalHealth = totalHealth + state.BattleEnemiesSelected[i].health;
  }

  if(state.gameScene == BATTLE_RANGED && doublefort)
    return;

  totalAttack = totalAttack + state.avSiegeAttack / ((physRes) ? 2 : 1);
  totalAttack = totalAttack + state.avSiegeIceAttack / ((iceRes) ? 2 : 1);
  totalAttack = totalAttack + state.avSiegeFireAttack / ((fireRes) ? 2 : 1);
  totalAttack = totalAttack + state.avSiegeColdFireAttack / ((coldFireRes) ? 2 : 1);

  if(!(state.gameScene == BATTLE_RANGED && fort)){
    totalAttack = totalAttack + state.avRangedAttack / ((physRes) ? 2 : 1);
    totalAttack = totalAttack + state.avRangedIceAttack / ((iceRes) ? 2 : 1);
    totalAttack = totalAttack + state.avRangedFireAttack / ((fireRes) ? 2 : 1);
    totalAttack = totalAttack + state.avRangedColdFireAttack / ((coldFireRes) ? 2 : 1);
  }

  if(state.gameScene == BATTLE_ATTACK){
    totalAttack = totalAttack + state.avAttack / ((physRes) ? 2 : 1);
    totalAttack = totalAttack + state.avIceAttack / ((iceRes) ? 2 : 1);
    totalAttack = totalAttack + state.avFireAttack / ((fireRes) ? 2 : 1);
    totalAttack = totalAttack + state.avColdFireAttack / ((coldFireRes) ? 2 : 1);
  }

  if(totalAttack >= totalHealth){
    for(int i = 0; i < state.BattleEnemiesSelected.size(); i++)
      state.fameToGain = state.fameToGain + state.BattleEnemiesSelected[i].fameReward;

    state.BattleEnemiesSelected.clear();

    state.avAttack = 0;
    state.avRangedAttack = 0;
    state.avSiegeAttack = 0;
    state.avFireAttack = 0;
    state.avRangedFireAttack = 0;
    state.avSiegeFireAttack = 0;
    state.avIceAttack = 0;
    state.avRangedIceAttack = 0;
    state.avSiegeIceAttack = 0;
    state.avColdFireAttack = 0;
    state.avRangedColdFireAttack = 0;
    state.avSiegeColdFireAttack = 0;
  }
}

void Game::stepSelectEnemy(int actionParam){
  if(state.gameScene != BATTLE_RANGED && state.gameScene != BATTLE_ATTACK && state.gameScene != BATTLE_BLOCK)
    return;
  if(actionParam < 0 || actionParam >= state.BattleEnemies.size())
    return;

  state.BattleEnemiesSelected.push_back(state.BattleEnemies[actionParam]);
  state.BattleEnemies.erase(state.BattleEnemies.begin() + actionParam);
}

void Game::stepSelectAttackToAssign(int actionParam){
  if(state.gameScene != BATTLE_ASSIGN)
    return;
  if(actionParam < 0 || actionParam >= state.BattleAttacksToAssign.size() || state.BattleAttacksSelected.size() > 0)
    return;

  state.BattleAttacksSelected.push_back(state.BattleAttacksToAssign[actionParam]);
  state.BattleAttacksToAssign.erase(state.BattleAttacksToAssign.begin() + actionParam);
}

void Game::stepBlockEnemy(int actionParam){
  if(state.gameScene != BATTLE_BLOCK || state.BattleEnemiesSelected.size() != 1)
    return;

  ENEMY e = state.BattleEnemiesSelected[0];

  if(actionParam < 0 || actionParam >= e.attacks.size() || e.attacks[actionParam].blocked)
    return;

  ENEMY_ATTACK at = e.attacks[actionParam];

  int totalBlock = 0;
  totalBlock = totalBlock + state.avBlock / ((at.type != PHYSICAL) ? 2 : 1);
  totalBlock = totalBlock + state.avFireBlock / ((at.type != PHYSICAL && at.type != ICE) ? 2 : 1);
  totalBlock = totalBlock + state.avIceBlock / ((at.type != PHYSICAL && at.type != FIRE) ? 2 : 1);
  totalBlock = totalBlock + state.avColdFireBlock;

  if(totalBlock >= at.attack){
    state.BattleEnemiesSelected[0].attacks[actionParam].blocked = true;

    //Ice Shield Strong Effect
    if(state.IceShieldStrong){
      state.IceShieldStrong = false;
      state.BattleEnemiesSelected[0].health = state.BattleEnemiesSelected[0].health - 3;
      if(state.BattleEnemiesSelected[0].health < 1)
        state.BattleEnemiesSelected[0].health = 1;
    }

    //Check if all attacks of this enemy were blocked
    state.BattleEnemiesSelected[0].blocked = true;
    for(int i = 0; i < state.BattleEnemiesSelected[0].attacks.size(); i++)
      if(!state.BattleEnemiesSelected[0].attacks[i].blocked)
        state.BattleEnemiesSelected[0].blocked = false;

    //De-select the enemy
    state.BattleEnemies.push_back(state.BattleEnemiesSelected[0]);
    state.BattleEnemiesSelected.clear();

    clearStateAvs();
  }

}

void Game::stepAssingDamageUnit(int actionParam){
  if(state.gameScene != BATTLE_ASSIGN || state.BattleAttacksSelected.size() != 1 || actionParam < 0 || actionParam >= state.PlayerUnits.size())
    return;

  if(state.PlayerUnits[actionParam]->isWounded())
    return;

  //TODO: Do something

  state.BattleAttacksSelected.clear();
}

void Game::stepAssingDamagePlayer(int actionParam){
  if(state.gameScene != BATTLE_ASSIGN || state.BattleAttacksSelected.size() != 1)
    return;

  //Do something
  int atk = state.BattleAttacksSelected[0].attack;
  while(atk > 0){
    atk = atk - state.playerArmor;
    state.playerHand.push_back(new Wound());
  }

  state.BattleAttacksSelected.clear();
}

void Game::stepAdvanceBattlePhase(int actionParam){
  if(state.gameScene != BATTLE_BLOCK && state.gameScene != BATTLE_RANGED && state.gameScene != BATTLE_ATTACK && state.gameScene != BATTLE_ASSIGN)
    return;

  clearStateAvs();

  for(int i = 0; i < state.BattleEnemiesSelected.size(); i++)
    state.BattleEnemies.push_back(state.BattleEnemiesSelected[i]);
  state.BattleEnemiesSelected.clear();

  if(state.gameScene == BATTLE_ATTACK){
    state.gameScene = MOVE_AND_EXPLORE;

    state.AgilityStrong = false;
    state.AgilityWeak = false;

    if(state.BattleEnemies.size() == 0 && state.BattleEnemiesSelected.size() == 0){
      //Remove Token from map
      if(state.rampagingHexAttacked != NULL){
        state.rampagingHexAttacked->location = NONEL;
        state.rampagingHexAttacked->faceUpEnemyToken.enemyType = NONEE;
        state.rampagingHexAttacked = NULL;
      }
      if(state.assaultingSite){
        state.assaultingSite = false;
        state.curHex->faceUpEnemyToken.enemyType = NONEE;
        state.curHex->faceUpEnemyToken2.enemyType = NONEE;
        this->onConquerSite();
      }

    }
    else{
      if(state.assaultingSite){
        state.assaultingSite = false;
        state.curHex->faceUpEnemyToken2 = state.curHex->faceUpEnemyToken;
        state.curHex->faceUpEnemyToken.enemyType = NONEE;
      }
      //TODO: Forced Retreat
    }
    state.BattleEnemies.clear();
    state.BattleEnemiesSelected.clear();
  }

  else if(state.gameScene == BATTLE_RANGED){
    state.gameScene = BATTLE_BLOCK;

    //TODO: Deal with attacks that are summons
  }

  else if(state.gameScene == BATTLE_BLOCK){
    state.BattleAttacksSelected.clear();
    state.BattleAttacksToAssign.clear();
    for(int i = 0; i < state.BattleEnemies.size(); i++){
      for(int j = 0; j < state.BattleEnemies[i].attacks.size(); j++){
        if(!state.BattleEnemies[i].attacks[j].blocked)
          state.BattleAttacksToAssign.push_back(state.BattleEnemies[i].attacks[j]);
      }
    }

    state.gameScene = BATTLE_ASSIGN;
    state.IceShieldStrong = false;
  }

  else if(state.gameScene == BATTLE_ASSIGN){
    if(state.BattleAttacksToAssign.size() > 0 || state.BattleAttacksSelected.size() > 0)
      return;

    state.gameScene = BATTLE_ATTACK;
  }
}

void Game::clearStateAvs(){
  state.avAttack = 0;
  state.avFireAttack = 0;
  state.avIceAttack = 0;
  state.avColdFireAttack = 0;
  state.avRangedAttack = 0;
  state.avRangedFireAttack = 0;
  state.avRangedIceAttack = 0;
  state.avRangedColdFireAttack = 0;
  state.avSiegeAttack = 0;
  state.avSiegeFireAttack = 0;
  state.avSiegeIceAttack = 0;
  state.avSiegeColdFireAttack = 0;

  state.avBlock = 0;
  state.avFireBlock = 0;
  state.avIceBlock = 0;
  state.avColdFireBlock = 0;
  state.avHeal = 0;
  state.avMove = 0;
  state.avInfluence = 0;
}

void Game::clearSpecialEffects(){
  state.ManaDrawWeak = false;
  state.ConcentrationStrong = false;
  state.TovakIDontGiveADamn = false;
  state.IceShieldStrong = false;
  state.AgilityStrong = false;
  state.AgilityWeak = false;
  state.PathFindingWeak = false;
  state.PathFindingStrong = false;
  state.SongOfWindWeak = false;
  state.SongOfWindStrong = false;
  state.SongOfWindStrongBlue = false;
  state.FrostBridgeWeak = false;
  state.FrostBridgeStrong = false;
}

void Game::gainSkill(){
  Skill *s1, *s2;

  s1 = state.SkillsNotObtained[0];
  s2 = state.SkillsNotObtained[1];

  state.SkillsNotObtained.erase(state.SkillsNotObtained.begin());
  state.SkillsNotObtained.erase(state.SkillsNotObtained.begin());

  std::vector<std::string> choices;
  choices.push_back(s1->getName());
  choices.push_back(s2->getName());

  int choice = state.player->chooseOption(choices);

  if(choice == 0) {
    state.SkillsObtained.push_back(s1);
    delete s2;
  }
  if(choice == 1){
    state.SkillsObtained.push_back(s2);
    delete s1;
  }
}

void Game::gainAdvancedAction(){
  std::vector<std::string> choices;
  choices.push_back(state.advancedActionsOffer[0]->getName());
  choices.push_back(state.advancedActionsOffer[1]->getName());
  choices.push_back(state.advancedActionsOffer[2]->getName());

  int choice = state.player->chooseOption(choices);

  if(state.advancedActionsOffer[choice] == NULL)
    return;

  state.playerDeedDeck.addCardTop(state.advancedActionsOffer[choice]);
  state.advancedActionsOffer[choice] = NULL;

  if(choice == 2){
    state.advancedActionsOffer[2] = state.advancedActionsOffer[1];
    state.advancedActionsOffer[1] = state.advancedActionsOffer[0];
  }
  if(choice == 1){
    state.advancedActionsOffer[1] = state.advancedActionsOffer[0];
  }
  state.advancedActionsOffer[0] = state.advancedActionsDeck.drawCard();
}

void Game::gainSpell(){

}

void Game::onConquerSite(){
  state.curHex->hasShieldToken = true;

  if(state.curHex->location == TOWER)
    state.spellsToGain++;

  if(state.curHex->location == KEEP){
    state.playerKeepsConquered++;
    state.playerHandSizeBonus = state.playerKeepsConquered;
  }
}
