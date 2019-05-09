#ifndef DEFINES_H
#define DEFINES_H

#include <vector>

#include "Cards/Deck.h"
#include "Map.h"

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

  Deck playerDeedDeck;
  Deck advancedActionsDeck;
  Deck artifactsDeck;
  Deck spellsDeck;

  bool isDayNight;         //True for day, False for night.

  int avAttack, avBlock, avMove, avInfluence; //Available Attack, Block, Move and Influence.
} STATE;

enum ACTION {NOTHING, USE_CARD_WEAK, USE_CARD_STRONG, MOVE_TO_ADJACENT_HEX};

#endif
