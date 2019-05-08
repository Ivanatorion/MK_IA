#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Cards/Card.h"
#include "Map.h"

typedef struct stado{
  std::vector<Card*> hand; //Cards in the player hand.
  int handMaxSize;         //Maximum cards the player can hold.
  int exp;                 //The ammount of "fame" the player has.
  int curTile;             //curTile = number of the tile (in game number)
  int curTileN;            //curTileN = number of the tile (in map position)
  int curHexN;             //Number of the Hex in the tile
  HEX *curHex;

  Map *m; //The map.

  int avAttack, avBlock, avMove, avInfluence; //Available Attack, Block, Move and Influence.
} STATE;

enum ACTION {NOTHING, USE_CARD_WEAK, USE_CARD_STRONG, MOVE_TO_ADJACENT_HEX};

class Game{
  public:
    Game();

    //The "step" function makes the game "state" transition based on input "action/actionParam".
    void step(ACTION action, int actionParam);

    //Returns the current game state.
    STATE getState(){return state;}

    //Prints information about the current state.
    void printState();

  private:
    STATE state;
};

#endif
