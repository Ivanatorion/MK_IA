#ifndef MAP_H
#define MAP_H

#include <vector>

#include "Enemy.h"

#define NUM_TILES 15
#define NUM_COUNTRYSIDE_TILES 7

enum TERRAIN {PLAIN, FOREST, DESERT, HILL, LAKE, MOUNTAIN, WASTELAND, SWAMP, NONET};
enum LOCATION {VILLAGE, MINEG, MINEB, MINER, MINEW, MINEBG, MINERW, GLADE, ORC, TOWER, KEEP, MONASTERY, DEN, RUIN, DUNGEON, CAMP, MAZE, CITY_RED, CITY_GREEN, CITY_BLUE, CITY_WHITE, NONEL};

typedef struct hex{
  struct hex *neighboors[6];
  bool hasWall[6];  //Up, Uright, Dright, Down, Dleft, Uleft
  TERRAIN terrain;
  LOCATION location;
  ENEMY rampagingEnemy;
} HEX;

typedef struct til{
  int tileN;
  HEX *hexes[7];
  bool core;
} TILE;

class Map{
  public:
    Map();
    bool revealTile(int tilePos);        //Reveals a tile at a position.
    TILE getTile(int p);                 //Returns the tile that is in the giver position "p" on the map. (Tile with tileN -1 if not revealed).
    void printStack();                   //Prints the current tile stack.
    int getMoveCost(HEX h, bool isDay);  //Returns the move cost to enter Hex

  private:
    std::vector<TILE> tileStack;
    TILE tiles[NUM_TILES];
    bool tilesRevealed[NUM_TILES];
    void shuffleTiles();                 //Shuffles the tiles (tiles).
    void initTileStack();                //Initializes the stack of tiles (tileStack).
    HEX outsideOfMap;                    //Dummy Hex to indicate out of map neighboor.
};

#endif
