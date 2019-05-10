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
      tiles[i].hexes[j] = new HEX;

      //Gets the terrain type of current hex.
      switch(fgetc(fp)){
        case 'H':
          tiles[i].hexes[j]->terrain = HILL;
          break;
        case 'P':
          tiles[i].hexes[j]->terrain = PLAIN;
          break;
        case 'L':
          tiles[i].hexes[j]->terrain = LAKE;
          break;
        case 'F':
          tiles[i].hexes[j]->terrain = FOREST;
          break;
        case 'D':
          tiles[i].hexes[j]->terrain = DESERT;
          break;
        case 'W':
          tiles[i].hexes[j]->terrain = WASTELAND;
          break;
        case 'S':
          tiles[i].hexes[j]->terrain = SWAMP;
          break;
        case 'M':
          tiles[i].hexes[j]->terrain = MOUNTAIN;
          break;
        case 'N':
          tiles[i].hexes[j]->terrain = NONET;
          break;
      }

      //Gets the location ant current hex.
      switch(fgetc(fp)){
        case 'N':
          tiles[i].hexes[j]->location = NONEL;
          break;
        case 'V':
          tiles[i].hexes[j]->location = VILLAGE;
          break;
        case 'G':
          tiles[i].hexes[j]->location = GLADE;
          break;
        case 'O':
          tiles[i].hexes[j]->location = ORC;
          break;
        case 'T':
          tiles[i].hexes[j]->location = TOWER;
          break;
        case 'K':
          tiles[i].hexes[j]->location = KEEP;
          break;
        case 'M':
          tiles[i].hexes[j]->location = MONASTERY;
          break;
        case 'D':
          tiles[i].hexes[j]->location = DEN;
          break;
        case 'd':
          tiles[i].hexes[j]->location = DUNGEON;
          break;
        case 'A':
          tiles[i].hexes[j]->location = CAMP;
          break;
        case 'R':
          tiles[i].hexes[j]->location = RUIN;
          break;
        case 'Z':
          tiles[i].hexes[j]->location = MAZE;
          break;
        case 'b':
          tiles[i].hexes[j]->location = MINEB;
          break;
        case 'g':
          tiles[i].hexes[j]->location = MINEG;
          break;
        case 'r':
          tiles[i].hexes[j]->location = MINER;
          break;
        case 'w':
          tiles[i].hexes[j]->location = MINEW;
          break;
        case 'y':
          tiles[i].hexes[j]->location = MINEBG;
          break;
        case 'p':
          tiles[i].hexes[j]->location = MINERW;
          break;
      }

    }
    fgetc(fp); //\n
  }

  fclose(fp);

  for(int i = 0; i < NUM_TILES; i++)
    for(int j = 0; j < 7; j++)
      for(int k = 0; k < 6; k++)
        tiles[i].hexes[j]->neighboors[k] = NULL;

  //Initialize know neighboors.
  for(int i = 0; i < NUM_TILES; i++){
    tiles[i].hexes[0]->neighboors[3] = tiles[i].hexes[1];
    tiles[i].hexes[0]->neighboors[4] = tiles[i].hexes[2];
    tiles[i].hexes[0]->neighboors[5] = tiles[i].hexes[3];

    tiles[i].hexes[1]->neighboors[2] = tiles[i].hexes[0];
    tiles[i].hexes[1]->neighboors[4] = tiles[i].hexes[3];
    tiles[i].hexes[1]->neighboors[5] = tiles[i].hexes[4];

    tiles[i].hexes[2]->neighboors[1] = tiles[i].hexes[0];
    tiles[i].hexes[2]->neighboors[3] = tiles[i].hexes[3];
    tiles[i].hexes[2]->neighboors[5] = tiles[i].hexes[5];

    tiles[i].hexes[3]->neighboors[0] = tiles[i].hexes[0];
    tiles[i].hexes[3]->neighboors[1] = tiles[i].hexes[1];
    tiles[i].hexes[3]->neighboors[2] = tiles[i].hexes[2];
    tiles[i].hexes[3]->neighboors[3] = tiles[i].hexes[4];
    tiles[i].hexes[3]->neighboors[4] = tiles[i].hexes[5];
    tiles[i].hexes[3]->neighboors[5] = tiles[i].hexes[6];

    tiles[i].hexes[4]->neighboors[0] = tiles[i].hexes[1];
    tiles[i].hexes[4]->neighboors[2] = tiles[i].hexes[3];
    tiles[i].hexes[4]->neighboors[4] = tiles[i].hexes[6];

    tiles[i].hexes[5]->neighboors[0] = tiles[i].hexes[2];
    tiles[i].hexes[5]->neighboors[1] = tiles[i].hexes[3];
    tiles[i].hexes[5]->neighboors[3] = tiles[i].hexes[6];

    tiles[i].hexes[6]->neighboors[0] = tiles[i].hexes[3];
    tiles[i].hexes[6]->neighboors[1] = tiles[i].hexes[4];
    tiles[i].hexes[6]->neighboors[2] = tiles[i].hexes[5];
  }

  for(int i = 0; i < NUM_TILES; i++){
    tiles[i].tileN = i;
    tilesRevealed[i] = false;
  }
  tilesRevealed[0] = true;

  this->initTileStack();
}

void Map::revealTile(int tilePos){
  if(tilesRevealed[tilePos])
    return;

  tiles[tilePos] = tileStack[0];
  tileStack.erase(tileStack.begin());
  tilesRevealed[tilePos] = true;
}

TILE Map::getTile(int p){
  TILE dummy;
  dummy.tileN = -1;

  return (tilesRevealed[p]) ? tiles[p] : dummy;
}

void Map::initTileStack(){
  tileStack.clear();
  this->shuffleTiles();
  for(int i = 0; i < NUM_COUNTRYSIDE_TILES; i++)
    tileStack.push_back(tiles[i+1]);
}

void Map::printStack(){
  for(int i = 0; i < tileStack.size(); i++)
    printf("%d\n", tileStack[i].tileN);
}

void Map::shuffleTiles(){
  const int swaps = 500;
  TILE auxtile;
  int t1, t2;
  for(int i = 0; i < swaps; i++){
    t1 = rand()%(NUM_TILES-1) + 1;
    t2 = rand()%(NUM_TILES-1) + 1;
    auxtile = tiles[t1];
    tiles[t1] = tiles[t2];
    tiles[t2] = auxtile;
  }
}
