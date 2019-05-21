#ifndef MAP_H
#define MAP_H

#include <vector>

#include "Enemy.h"

#define NUM_TILES 15               //Number of tile spots on the map
#define NUM_COUNTRYSIDE_TILES 15   //Number of CountrySide Tiles
#define NUM_CORE_TILES 6           //Number of Core Tiles
#define NUM_CITY_TILES 4           //Number of Core Tiles
#define NUM_TOTAL_TILES 25         //Total Tiles in the game

#define NUM_COUNTRYSIDE_TILES_ON_STACK 7
#define NUM_CORE_TILES_ON_STACK 4

enum TERRAIN {PLAIN, FOREST, DESERT, HILL, LAKE, MOUNTAIN, WASTELAND, SWAMP, NONET};
enum LOCATION {VILLAGE, MINEG, MINEB, MINER, MINEW, MINEBG, MINERW, MINEALL, GLADE, ORC, TOWER, KEEP, MONASTERY, DEN, RUIN, DUNGEON, CAMP, MAZE, TOMB, DRACONUM, SPAWNINGGROUNDS, LABYRINTH, CITY_RED, CITY_GREEN, CITY_BLUE, CITY_WHITE, NONEL};

typedef struct hex{
  struct hex *neighboors[6];
  bool hasWall[6];                 //UpLeft, UpRight, Right, DRight, Dleft, left
  TERRAIN terrain;                 //Type of the terrain
  LOCATION location;               //Type of the location
  ENEMY faceUpEnemyToken;          //Information on the enemy token on this tile.
  ENEMY faceUpEnemyToken2;         //Only Used on SpawningGrounds.
  ENEMY_TYPE faceDownEnemyToken;   //Type of the enemy token that is face down on this hex (NONEE if none)
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
    int getMoveCost(HEX h, bool isDay);  //Returns the move cost to enter Hex
    bool isCoreTileRevealed();           //Returns true if there is a Core Tile revealed on the Map

    ENEMY getEnemy(ENEMY_TYPE type);

  private:
    std::vector<TILE> tileStack;
    TILE tiles[NUM_TOTAL_TILES];
    bool tilesRevealed[NUM_TILES];
    void initTileStack();                //Initializes the stack of tiles (tileStack).
    HEX outsideOfMap;                    //Dummy Hex to indicate out of map neighboor.

    std::vector<ENEMY> greenEnemies;
    std::vector<ENEMY> purpleEnemies;
    std::vector<ENEMY> brownEnemies;
    std::vector<ENEMY> greyEnemies;
    std::vector<ENEMY> whiteEnemies;
    std::vector<ENEMY> redEnemies;

    void loadEnemies(ENEMY_TYPE type);
};

#endif
