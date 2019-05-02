#ifndef MAP_H
#define MAP_H

#define NUM_TILES 14
#define SHUFFLE_SWAPS 300

enum TERRAIN {PLAIN, FOREST, DESERT, HILL, LAKE, MOUNTAIN, WASTELAND, SWAMP, NONET};
enum LOCATION {VILLAGE, MINE, NONEL};

typedef struct hex{
  struct hex *neighboors[7];
  TERRAIN terrain;
  LOCATION location;
} HEX;

typedef struct til{
  int tileN;
  HEX hexes[7];
  bool core;
} TILE;

class Map{
  public:
    Map();
    void revealTile(int tilePos);

  private:
    TILE tiles[NUM_TILES];
    bool tilesRevealed[NUM_TILES];
    void shuffleTiles();
};

#endif
