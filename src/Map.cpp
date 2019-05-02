#include <cstdlib>
#include <cstdio>
#include "../include/Map.h"

Map::Map(){

  //INIT ALL TILES HERE


  for(int i = 0; i < NUM_TILES; i++){
    tiles[i].tileN = i+1;
    tilesRevealed[i] = false;
  }

  this->shuffleTiles();
}

void Map::revealTile(int tilePos){

  tilesRevealed[tilePos] = true;
}

void Map::shuffleTiles(){
  TILE auxtile;
  int t1, t2;
  for(int swaps = SHUFFLE_SWAPS; swaps > 0; swaps--){
    t1 = rand()%NUM_TILES;
    t2 = rand()%NUM_TILES;
    auxtile = tiles[t1];
    tiles[t1] = tiles[t2];
    tiles[t2] = auxtile;
  }
}
