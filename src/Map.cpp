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

  outsideOfMap.terrain = NONET;
  outsideOfMap.location = NONEL;

  //Initialize Hexes infromation.
  for(int i = 0; i < NUM_TILES; i++){
    for(int j = 0; j < 7; j++){
      tiles[i].hexes[j] = new HEX;
      tiles[i].hexes[j]->rampagingEnemy.enemyType = NONEE;

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

  tiles[0].hexes[0]->neighboors[2] = &outsideOfMap;

  this->initTileStack();
}

bool Map::revealTile(int tilePos){
  if(tilePos < 0 || tilePos > NUM_TILES - 1 || tilesRevealed[tilePos])
    return false;

  tiles[tilePos] = tileStack[0];
  tileStack.erase(tileStack.begin());
  tilesRevealed[tilePos] = true;

  //Adjusts neighboors
  static const short int refTable[NUM_TILES][6] = {{ 2, 1,-1,-1,-1,-1},
                                                   { 4, 3,-1,-1, 0, 2},
                                                   { 4, 4, 1, 0,-1,-1},
                                                   { 7, 6,-1,-1, 1, 4},
                                                   { 8, 7, 3, 1, 2, 5},
                                                   { 9, 8, 4, 2,-1,-1},
                                                   {11,10,-1,-1, 3, 7},
                                                   {12,11, 6, 3, 4, 8},
                                                   {13,12, 7, 4, 5, 9},
                                                   {14,13, 8, 5,-1,-1},
                                                   {-1,-1,-1,-1, 6,11},
                                                   {-1,-1,10, 6, 7,12},
                                                   {-1,-1,11, 7, 8,13},
                                                   {-1,-1,12, 8, 9,14},
                                                   {-1,-1,13, 9,-1,-1}};

  TILE *curT;
  TILE *tileRev = &tiles[tilePos];
  for(int i = 0; i < 6; i++){
    if(refTable[tilePos][i] != -1 && tilesRevealed[refTable[tilePos][i]]){
      curT = &tiles[refTable[tilePos][i]];
      switch (i) {
        case 0:
          curT->hexes[5]->neighboors[5] = tileRev->hexes[0];
          curT->hexes[6]->neighboors[4] = tileRev->hexes[0];
          curT->hexes[6]->neighboors[5] = tileRev->hexes[1];
          tileRev->hexes[0]->neighboors[0] = curT->hexes[5];
          tileRev->hexes[0]->neighboors[1] = curT->hexes[6];
          tileRev->hexes[1]->neighboors[0] = curT->hexes[6];
          break;
        case 1:
          curT->hexes[2]->neighboors[4] = tileRev->hexes[1];
          curT->hexes[5]->neighboors[2] = tileRev->hexes[1];
          curT->hexes[5]->neighboors[4] = tileRev->hexes[4];
          tileRev->hexes[1]->neighboors[1] = curT->hexes[2];
          tileRev->hexes[1]->neighboors[3] = curT->hexes[5];
          tileRev->hexes[4]->neighboors[1] = curT->hexes[5];
          break;
        case 2:
          curT->hexes[0]->neighboors[2] = tileRev->hexes[4];
          curT->hexes[2]->neighboors[0] = tileRev->hexes[4];
          curT->hexes[2]->neighboors[2] = tileRev->hexes[6];
          tileRev->hexes[4]->neighboors[3] = curT->hexes[0];
          tileRev->hexes[4]->neighboors[5] = curT->hexes[2];
          tileRev->hexes[6]->neighboors[3] = curT->hexes[2];
          break;
        case 3:
          curT->hexes[0]->neighboors[0] = tileRev->hexes[5];
          curT->hexes[0]->neighboors[1] = tileRev->hexes[6];
          curT->hexes[1]->neighboors[0] = tileRev->hexes[6];
          tileRev->hexes[5]->neighboors[5] = curT->hexes[0];
          tileRev->hexes[6]->neighboors[4] = curT->hexes[0];
          tileRev->hexes[6]->neighboors[5] = curT->hexes[1];
          break;
        case 4:
          curT->hexes[1]->neighboors[1] = tileRev->hexes[2];
          curT->hexes[1]->neighboors[3] = tileRev->hexes[5];
          curT->hexes[4]->neighboors[1] = tileRev->hexes[5];
          tileRev->hexes[2]->neighboors[4] = curT->hexes[1];
          tileRev->hexes[5]->neighboors[2] = curT->hexes[1];
          tileRev->hexes[5]->neighboors[4] = curT->hexes[4];
          break;
        case 5:
          curT->hexes[4]->neighboors[3] = tileRev->hexes[0];
          curT->hexes[4]->neighboors[5] = tileRev->hexes[2];
          curT->hexes[6]->neighboors[3] = tileRev->hexes[2];
          tileRev->hexes[0]->neighboors[2] = curT->hexes[4];
          tileRev->hexes[2]->neighboors[0] = curT->hexes[4];
          tileRev->hexes[2]->neighboors[2] = curT->hexes[6];
          break;
      }
    }
  }

  return true;
}

int Map::getMoveCost(HEX h, bool isDay){
  int result;

  switch (h.terrain) {
    case NONET:
    case LAKE:
    case MOUNTAIN:
      result = 99;
      break;
    case PLAIN:
      result = 2;
      break;
    case HILL:
      result = 3;
      break;
    case FOREST:
      result = (isDay) ? 3 : 5;
      break;
    case DESERT:
      result = (isDay) ? 5 : 3;
      break;
    case WASTELAND:
      result = 4;
      break;
    case SWAMP:
      result = 5;
      break;
  }

  return result;
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
