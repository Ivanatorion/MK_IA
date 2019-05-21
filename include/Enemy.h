#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <string>
#include <utility>

enum ATTACK_TYPE {PHYSICAL, ICE, FIRE, COLDFIRE, SUMMON};
enum ENEMY_TYPE {E_ORC, E_DRAKE, E_DUNGEON, E_MAGE, E_KEEP, E_CITY, NONEE};

typedef struct atk{
  bool blocked;
  int attack;
  ATTACK_TYPE type;
} ENEMY_ATTACK;

typedef struct enem{
  int health;
  int fameReward;
  std::vector<ENEMY_ATTACK> attacks;
  bool pRes, fRes, iRes;
  bool fortified, unfortified, elusive, brutal, poison, swift, petrify, cumbersome, arcaneImune, assassin;
  ENEMY_TYPE enemyType;
  std::string name;

  bool blocked, doubleFortified;
} ENEMY;

#endif
