#ifndef DEFINES_H
#define DEFINES_H

#include <vector>

#include "Cards/Deck.h"
#include "Map.h"

#define N_DICE_IN_SOURCE 3
#define N_UNITS_IN_OFFER 3

enum COLOR {RED, GREEN, BLUE, WHITE, GOLD, BLACK, NONE}; //NONE for Artifacts
enum CARDTYPE {ACTIONCARD, SPELLCARD, ARTIFACTCARD, WOUND};

class Player;
class Unit;
typedef struct stado{
  bool gameRunning;        //Game is running.
  bool gameOver;           //Game should end.

  std::vector<Unit*> PlayerUnits;
  std::vector<Unit*> UnitOffer;
  std::vector<Unit*> RegularUnitsDeck;
  std::vector<Unit*> EliteUnitsDeck;

  std::vector<Card*> hand; //Cards in the player hand.
  int handMaxSize;         //Maximum cards the player can hold.
  int currentRound;        //Current game round.
  int exp;                 //The ammount of "fame" the player has.
  int reputation;          //The level of reputation.
  int curTile;             //curTile = number of the tile (in game number)
  int curTileN;            //curTileN = number of the tile (in map position)
  int curHexN;             //Number of the Hex in the tile
  HEX *curHex;

  Map *m; //The map.

  int playerCrystalsRed, playerCrystalsWhite, playerCrystalsGreen, playerCrystalsBlue;
  int playerTokensRed, playerTokensWhite, playerTokensGreen, playerTokensBlue, playerTokensBlack;

  Deck playerDiscardDeck;
  Deck playerDeedDeck;
  Deck advancedActionsDeck;
  Deck artifactsDeck;
  Deck spellsDeck;

  Card *spellOffer[3];
  Card *advancedActionsOffer[3];

  COLOR sourceDice[N_DICE_IN_SOURCE];
  bool diceTaken;

  bool isDayNight;         //True for day, False for night.

  int avHeal;
  int avAttack, avBlock, avMove, avInfluence; //Available Attack, Block, Move and Influence.
  int avFireAttack, avFireBlock, avIceAttack, avIceBlock, avColdFireAttack, avColdFireBlock;
  int avRangedAttack, avRangedFireAttack, avRangedIceAttack, avRangedColdFireAttack;
  int avSiegeAttack, avSiegeFireAttack, avSiegeIceAttack, avSiegeColdFireAttack;

  Player *player;

  //Card vars
  bool ManaDrawWeakActive;
  bool ConcentrationNextCard;

  //End Turn
  int fameToGain;
  int repToGain;
} STATE;

enum ACTION {NOTHING, USE_CARD_WEAK, USE_CARD_STRONG, USE_CARD_SIDEWAYS, USE_UNIT, MOVE_TO_ADJACENT_HEX, TAKE_DIE_FROM_SOURCE, RECRUIT_UNIT, REVEAL_ADJEACENT_TILE, END_TURN, QUIT_GAME};

#endif
