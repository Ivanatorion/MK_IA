#ifndef DEFINES_H
#define DEFINES_H

#include <vector>

#include "Cards/Deck.h"
#include "Map.h"

#define N_DICE_IN_SOURCE 3

enum COLOR {RED, GREEN, BLUE, WHITE, GOLD, BLACK, NONE}; //NONE for Artifacts
enum CARDTYPE {ACTIONCARD, SPELLCARD, ARTIFACTCARD};

class Player;
typedef struct stado{
  bool gameRunning;        //Game is running.
  bool gameOver;

  std::vector<Card*> hand; //Cards in the player hand.
  int handMaxSize;         //Maximum cards the player can hold.
  int exp;                 //The ammount of "fame" the player has.
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

  int avAttack, avBlock, avMove, avInfluence; //Available Attack, Block, Move and Influence.
  int avFireAttack, avFireBlock, avIceAttack, avIceBlock, avColdFireAttack, avColdFireBlock;
  int avRangedAttack, avRangedFireAttack, avRangedIceAttack, avRangedColdFireAttack;
  int avSiegeAttack, avSiegeFireAttack, avSiegeIceAttack, avSiegeColdFireAttack;

  Player *player;
} STATE;

enum ACTION {NOTHING, USE_CARD_WEAK, USE_CARD_STRONG, MOVE_TO_ADJACENT_HEX, TAKE_DIE_FROM_SOURCE};

#endif
