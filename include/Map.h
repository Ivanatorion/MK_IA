#ifndef MAP_H
#define MAP_H

#include <vector>

#define NUM_TILES 15
#define NUM_COUNTRYSIDE_TILES 7
#define SHUFFLE_SWAPS 300

enum TERRAIN {PLAIN, FOREST, DESERT, HILL, LAKE, MOUNTAIN, WASTELAND, SWAMP, NONET};
enum LOCATION {VILLAGE, MINEG, MINEB, MINER, MINEW, MINEBG, MINERW, GLADE, ORC, TOWER, KEEP, MONASTERY, DEN, RUIN, DUNGEON, CAMP, MAZE, NONEL};

typedef struct hex{
  struct hex *neighboors[6];
  bool hasWall[6];  //Up, Uright, Dright, Down, Dleft, Uleft
  TERRAIN terrain;
  LOCATION location;
} HEX;

typedef struct til{
  int tileN;
  HEX *hexes[7];
  bool core;
} TILE;

class Map{
  public:
    Map();
    void revealTile(int tilePos);        //Reveals a tile at a position.
    TILE getTile(int p);                 //Returns the tile that is in the giver position "p" on the map. (Tile with tileN -1 if not revealed).
    void printStack();                   //Prints the current tile stack.

  private:
    std::vector<TILE> tileStack;
    TILE tiles[NUM_TILES];
    bool tilesRevealed[NUM_TILES];
    void shuffleTiles();                 //Shuffles the tiles (tiles).
    void initTileStack();                //Initializes the stack of tiles (tileStack).
};

#endif
