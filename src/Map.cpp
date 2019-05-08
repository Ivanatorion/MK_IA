#include <cstdlib>
#include <cstdio>
#include "../include/Map.h"

#define TILE_INFO_FILE "res/TileHexInfo.txt"

Map::Map(){

  FILE *fp = fopen(TILE_INFO_FILE, "r");

  if(!fp){
      printf("Fatal Error: Could not open %c%s%c\n", 34, TILE_INFO_FILE, 34);
      exit(0);
  }

  //Initialize Hexes infromation.
  for(int i = 0; i < NUM_TILES; i++){
    for(int j = 0; j < 7; j++){

      //Gets the terrain type of current hex.
      switch(fgetc(fp)){
        case 'H':
          tileStack[i].hexes[j].terrain = HILL;
          break;
        case 'P':
          tileStack[i].hexes[j].terrain = PLAIN;
          break;
        case 'L':
          tileStack[i].hexes[j].terrain = LAKE;
          break;
        case 'F':
          tileStack[i].hexes[j].terrain = FOREST;
          break;
        case 'D':
          tileStack[i].hexes[j].terrain = DESERT;
          break;
        case 'W':
          tileStack[i].hexes[j].terrain = WASTELAND;
          break;
        case 'S':
          tileStack[i].hexes[j].terrain = SWAMP;
          break;
        case 'M':
          tileStack[i].hexes[j].terrain = MOUNTAIN;
          break;
      }

      //Gets the location ant current hex.
      switch(fgetc(fp)){
        case 'N':
          tileStack[i].hexes[j].location = NONEL;
          break;
        case 'V':
          tileStack[i].hexes[j].location = VILLAGE;
          break;
        case 'b':
          tileStack[i].hexes[j].location = MINEB;
          break;
        case 'g':
          tileStack[i].hexes[j].location = MINEG;
          break;
        case 'r':
          tileStack[i].hexes[j].location = MINER;
          break;
        case 'w':
          tileStack[i].hexes[j].location = MINEW;
          break;
        case 'G':
          tileStack[i].hexes[j].location = GLADE;
          break;
        case 'O':
          tileStack[i].hexes[j].location = ORC;
          break;
        case 'T':
          tileStack[i].hexes[j].location = TOWER;
          break;
      }

    }
    fgetc(fp); //\n
  }

  fclose(fp);

  //Initialize know neighboors.
  for(int i = 0; i < NUM_TILES; i++){
    

  }

  for(int i = 0; i < NUM_TILES; i++){
    tileStack[i].tileN = i+1;
    tilesRevealed[i] = false;
  }

  //this->shuffleTiles();
}

void Map::revealTile(int tilePos){

  tilesRevealed[tilePos] = true;
}

TILE Map::getTile(int p){
  return tileStack[p];
}

void Map::shuffleTiles(){
  TILE auxtile;
  int t1, t2;
  for(int swaps = SHUFFLE_SWAPS; swaps > 0; swaps--){
    t1 = rand()%NUM_TILES;
    t2 = rand()%NUM_TILES;
    auxtile = tileStack[t1];
    tileStack[t1] = tileStack[t2];
    tileStack[t2] = auxtile;
  }
}
