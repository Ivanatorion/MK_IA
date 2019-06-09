#include <cstdlib>
#include <cstdio>
#include "../include/Map.h"

#define TILE_INFO_FILE "res/TileHexInfo.dat"

Map::Map(){

  FILE *fp = fopen(TILE_INFO_FILE, "r");

  if(!fp){
      printf("Fatal Error: Could not open %c%s%c\n", 34, TILE_INFO_FILE, 34);
      exit(0);
  }

  outsideOfMap.terrain = NONET;
  outsideOfMap.location = NONEL;

  //Initialize Hexes infromation.
  for(int i = 0; i < NUM_TOTAL_TILES; i++){
    for(int j = 0; j < 7; j++){
      tiles[i].hexes[j] = new HEX;
      tiles[i].hexes[j]->faceUpEnemyToken.enemyType = NONEE;
      tiles[i].hexes[j]->faceUpEnemyToken2.enemyType = NONEE;
      tiles[i].hexes[j]->faceDownEnemyToken = NONEE;
      tiles[i].hexes[j]->hasShieldToken = false;

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
          tiles[i].hexes[j]->faceDownEnemyToken = E_MAGE;
          break;
        case 'K':
          tiles[i].hexes[j]->location = KEEP;
          tiles[i].hexes[j]->faceDownEnemyToken = E_KEEP;
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
        case 'B':
          tiles[i].hexes[j]->location = TOMB;
          break;
        case 'S':
          tiles[i].hexes[j]->location = SPAWNINGGROUNDS;
          break;
        case 'C':
          tiles[i].hexes[j]->location = DRACONUM;
          break;
        case 'L':
          tiles[i].hexes[j]->location = LABYRINTH;
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
        case 'a':
          tiles[i].hexes[j]->location = MINEALL;
          break;
        case '1':
          tiles[i].hexes[j]->location = CITY_GREEN;
          break;
        case '2':
          tiles[i].hexes[j]->location = CITY_BLUE;
          break;
        case '3':
          tiles[i].hexes[j]->location = CITY_WHITE;
          break;
        case '4':
          tiles[i].hexes[j]->location = CITY_RED;
          break;
      }

    }
    fgetc(fp); //\n
  }

  fclose(fp);

  for(int i = 0; i <NUM_TOTAL_TILES; i++)
    for(int j = 0; j < 7; j++)
      for(int k = 0; k < 6; k++)
        tiles[i].hexes[j]->neighboors[k] = NULL;

  //Initialize know neighboors.
  for(int i = 0; i < NUM_TOTAL_TILES; i++){
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

  for(int i = 0; i < NUM_TOTAL_TILES; i++)
    tiles[i].tileN = i;
  for(int i = 0; i < NUM_TILES; i++)
    tilesRevealed[i] = false;

  tilesRevealed[0] = true;

  tiles[0].hexes[0]->neighboors[2] = &outsideOfMap;
  tiles[0].hexes[2]->neighboors[0] = &outsideOfMap;
  tiles[0].hexes[2]->neighboors[2] = &outsideOfMap;
  tiles[0].hexes[2]->neighboors[4] = &outsideOfMap;
  tiles[0].hexes[5]->neighboors[2] = &outsideOfMap;
  tiles[0].hexes[5]->neighboors[4] = &outsideOfMap;
  tiles[0].hexes[5]->neighboors[5] = &outsideOfMap;
  tiles[0].hexes[6]->neighboors[3] = &outsideOfMap;
  tiles[0].hexes[6]->neighboors[4] = &outsideOfMap;
  tiles[0].hexes[6]->neighboors[5] = &outsideOfMap;

  this->initTileStack();

  greenEnemies.clear();
  purpleEnemies.clear();
  brownEnemies.clear();
  greyEnemies.clear();
  whiteEnemies.clear();
  redEnemies.clear();

  this->loadEnemies(E_ORC);
  this->loadEnemies(E_DRAKE);
  this->loadEnemies(E_DUNGEON);
  this->loadEnemies(E_MAGE);
  this->loadEnemies(E_KEEP);
  this->loadEnemies(E_CITY);
}

void Map::loadEnemies(ENEMY_TYPE type){
  std::string dataFile;
  const int swaps = 500;
  int p1, p2;

  switch (type) {
    case E_ORC:
      dataFile = "res/Enemies/GreenEnemies.dat";
      break;
    case E_DRAKE:
      dataFile = "res/Enemies/RedEnemies.dat";
      break;
    case E_DUNGEON:
      dataFile = "res/Enemies/BrownEnemies.dat";
      break;
    case E_MAGE:
      dataFile = "res/Enemies/PurpleEnemies.dat";
      break;
    case E_KEEP:
      dataFile = "res/Enemies/GreyEnemies.dat";
      break;
    case E_CITY:
      dataFile = "res/Enemies/WhiteEnemies.dat";
      break;
  }

  FILE *fp = fopen(dataFile.c_str(), "r");
  if(!fp){
    printf("Fatal Error: Could not open %s\n", dataFile.c_str());
    exit(0);
  }

  std::vector<ENEMY> read;
  ENEMY templ;
  ENEMY_ATTACK aTemplate;
  char c;
  int attackN = 0, enemN = 0, amtTok = 0;

  templ.enemyType = type;
  templ.doubleFortified = false;

  //Skip file Commentary
  c = fgetc(fp);
  while(c == '#'){
    while(c != '\n')
      c = fgetc(fp);
    c = fgetc(fp);
  }

  while(c != '\n'){
    enemN = enemN * 10 + (c - '0');
    c = fgetc(fp);
  }

  for(int x = 0; x < enemN; x++){
    templ.name.clear();
    c = fgetc(fp);
    while(c != '\n'){
      templ.name.push_back(c);
      c = fgetc(fp);
    }

    amtTok = 0;
    c = fgetc(fp);
    while(c != '\n'){
      amtTok = amtTok * 10 + (c - '0');
      c = fgetc(fp);
    }

    templ.health = 0;
    c = fgetc(fp);
    while(c != '\n'){
      templ.health = templ.health * 10 + (c - '0');
      c = fgetc(fp);
    }

    templ.fameReward = 0;
    c = fgetc(fp);
    while(c != '\n'){
      templ.fameReward = templ.fameReward * 10 + (c - '0');
      c = fgetc(fp);
    }

    templ.attacks.clear();
    attackN = fgetc(fp) - '0';
    fgetc(fp);
    for(int i = 0; i < attackN; i++){
      aTemplate.attack = 0;
      c = fgetc(fp);
      while(c != ','){
        aTemplate.attack = aTemplate.attack * 10 + (c - '0');
        c = fgetc(fp);
      }

      switch (fgetc(fp)) {
        case 'P':
          aTemplate.type = PHYSICAL;
          break;
        case 'F':
          aTemplate.type = FIRE;
          break;
        case 'I':
          aTemplate.type = ICE;
          break;
        case 'C':
          aTemplate.type = COLDFIRE;
          break;
        case 'S':
          aTemplate.type = SUMMON;
          break;
      }
      fgetc(fp);

      templ.attacks.push_back(aTemplate);
    }

    templ.pRes = (fgetc(fp) == 'T');
    templ.fRes = (fgetc(fp) == 'T');
    templ.iRes = (fgetc(fp) == 'T');

    fgetc(fp);

    templ.fortified = (fgetc(fp) == 'T');
    templ.unfortified = (fgetc(fp) == 'T');
    templ.elusive = (fgetc(fp) == 'T');
    templ.brutal = (fgetc(fp) == 'T');
    templ.poison = (fgetc(fp) == 'T');
    templ.swift = (fgetc(fp) == 'T');
    templ.petrify = (fgetc(fp) == 'T');
    templ.cumbersome = (fgetc(fp) == 'T');
    templ.arcaneImune = (fgetc(fp) == 'T');
    templ.assassin = (fgetc(fp) == 'T');

    for(int j = 0; j < amtTok; j++)
      read.push_back(templ);
    fgetc(fp);
  }

  fclose(fp);

  //Shuffle the enemies
  for(int i = 0; i < swaps; i++){
    p1 = rand()%(read.size());
    p2 = rand()%(read.size());

    templ = read[p1];
    read[p1] = read[p2];
    read[p2] = templ;
  }

  switch (type) {
    case E_ORC:
      greenEnemies = read;
      break;
    case E_DRAKE:
      redEnemies = read;
      break;
    case E_DUNGEON:
      brownEnemies = read;
      break;
    case E_MAGE:
      purpleEnemies = read;
      break;
    case E_KEEP:
      greyEnemies = read;
      break;
    case E_CITY:
      whiteEnemies = read;
      break;
  }
}

ENEMY Map::getEnemy(ENEMY_TYPE type){
  ENEMY result;
  switch (type) {
    case E_ORC:
      result = greenEnemies[greenEnemies.size()-1];
      greenEnemies.erase(greenEnemies.end() - 1);
      if(greenEnemies.size() == 0)
        loadEnemies(E_ORC);
      break;
    case E_DRAKE:
      result = redEnemies[redEnemies.size()-1];
      redEnemies.erase(redEnemies.end() - 1);
      if(redEnemies.size() == 0)
        loadEnemies(E_DRAKE);
      break;
    case E_DUNGEON:
      result = brownEnemies[brownEnemies.size()-1];
      brownEnemies.erase(brownEnemies.end() - 1);
      if(brownEnemies.size() == 0)
        loadEnemies(E_DUNGEON);
      break;
    case E_MAGE:
      result = purpleEnemies[purpleEnemies.size()-1];
      purpleEnemies.erase(purpleEnemies.end() - 1);
      if(purpleEnemies.size() == 0)
        loadEnemies(E_MAGE);
      break;
    case E_KEEP:
      result = greyEnemies[greyEnemies.size()-1];
      greyEnemies.erase(greyEnemies.end() - 1);
      if(greyEnemies.size() == 0)
        loadEnemies(E_KEEP);
      break;
    case E_CITY:
      result = whiteEnemies[whiteEnemies.size()-1];
      whiteEnemies.erase(whiteEnemies.end() - 1);
      if(whiteEnemies.size() == 0)
        loadEnemies(E_CITY);
      break;
  }
  return result;
}

bool Map::revealTile(int tilePos){
  if(tilePos < 0 || tilePos > NUM_TILES - 1 || tilesRevealed[tilePos])
    return false;

  tiles[tilePos] = tileStack[0];
  tileStack.erase(tileStack.begin());
  tilesRevealed[tilePos] = true;

  for(int i = 0; i < 7; i++){
    if(tiles[tilePos].hexes[i]->location == ORC)
      tiles[tilePos].hexes[i]->faceUpEnemyToken = this->getEnemy(E_ORC);

    if(tiles[tilePos].hexes[i]->location == DRACONUM)
      tiles[tilePos].hexes[i]->faceUpEnemyToken = this->getEnemy(E_DRAKE);

    if(tiles[tilePos].hexes[i]->location == KEEP)
      tiles[tilePos].hexes[i]->faceDownEnemyToken = E_KEEP;
  }

  //TODO: Adjust outsideOfMap
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
      result = 9999;
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
  const int swaps = 500;
  int p1, p2, p3, p4;
  TILE aux;

  tileStack.clear();

  for(int i = 0; i < swaps; i++){
      p1 = rand()%(NUM_COUNTRYSIDE_TILES-1) + 1;
      p2 = rand()%(NUM_COUNTRYSIDE_TILES-1) + 1;
      aux = tiles[p1];
      tiles[p1] = tiles[p2];
      tiles[p2] = aux;
  }

  for(int i = 0; i < swaps; i++){
    p1 = rand()%(NUM_CORE_TILES) + NUM_COUNTRYSIDE_TILES;
    p2 = rand()%(NUM_CORE_TILES) + NUM_COUNTRYSIDE_TILES;
    aux = tiles[p1];
    tiles[p1] = tiles[p2];
    tiles[p2] = aux;
  }

  for(int i = 0; i < swaps; i++){
    p1 = rand()%(NUM_CITY_TILES) + NUM_COUNTRYSIDE_TILES + NUM_CORE_TILES;
    p2 = rand()%(NUM_CITY_TILES) + NUM_COUNTRYSIDE_TILES + NUM_CORE_TILES;
    aux = tiles[p1];
    tiles[p1] = tiles[p2];
    tiles[p2] = aux;
  }

  aux = tiles[NUM_COUNTRYSIDE_TILES + NUM_CORE_TILES];
  tiles[NUM_COUNTRYSIDE_TILES + NUM_CORE_TILES] = tiles[NUM_COUNTRYSIDE_TILES];
  tiles[NUM_COUNTRYSIDE_TILES] = aux;

  aux = tiles[NUM_COUNTRYSIDE_TILES + NUM_CORE_TILES + 1];
  tiles[NUM_COUNTRYSIDE_TILES + NUM_CORE_TILES + 1] = tiles[NUM_COUNTRYSIDE_TILES + 1];
  tiles[NUM_COUNTRYSIDE_TILES + 1] = aux;

  for(int i = 0; i < swaps; i++){
    p1 = rand()%(NUM_CORE_TILES_ON_STACK) + NUM_COUNTRYSIDE_TILES;
    p2 = rand()%(NUM_CORE_TILES_ON_STACK) + NUM_COUNTRYSIDE_TILES;
    aux = tiles[p1];
    tiles[p1] = tiles[p2];
    tiles[p2] = aux;
  }

  for(int i = 0; i < NUM_COUNTRYSIDE_TILES_ON_STACK; i++)
    tileStack.push_back(tiles[i+1]);

  for(int i = 0; i < NUM_CORE_TILES_ON_STACK; i++)
    tileStack.push_back(tiles[NUM_COUNTRYSIDE_TILES+i]);
}

bool Map::isCoreTileRevealed(){
  return (tileStack.size() < NUM_CORE_TILES_ON_STACK);
}
