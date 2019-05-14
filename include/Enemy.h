#ifndef ENEMY_H
#define ENEMY_H

#include <vector>

enum ATTACK_TYPE {PHYSICAL, ICE, FIRE, COLDFIRE};
enum ENEMY_TYPE {E_ORC, E_DRAKE, E_DUNGEON, E_MAGE, E_KEEP, E_CITY, NONEE};

typedef struct enem{
  int health;
  std::vector<int> attacks;
  std::vector<ATTACK_TYPE> attackTypes;
  bool brutal, poison, fortified, pRes, fRes, iRes, swift;
  ENEMY_TYPE enemyType;
} ENEMY;

#endif
