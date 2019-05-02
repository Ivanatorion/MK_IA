#ifndef DEFINES_H
#define DEFINES_H

#include <vector>
#include "Cards/Card.h"
#include "Map.h"

typedef struct stado{
  std::vector<Card*> hand;
  int exp;
  Map m;
} STATE;

#endif
