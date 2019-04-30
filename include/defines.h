#ifndef DEFINES_H
#define DEFINES_H

#include "Cards/Card.h"

typedef struct stado{
  std::vector<Card*> hand;
  int exp;
} STATE;

#endif
