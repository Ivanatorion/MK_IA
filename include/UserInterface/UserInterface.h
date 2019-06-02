#ifndef UINTFACE
#define UINTFACE

#include "../defines.h"
#include "../Units/Unit.h"
#include "../Cards/Card.h"
#include "../Skills/Skill.h"
#include <string>

class UserInterface {
  public:
    virtual void printState(STATE state) = 0;
    std::string colorToString(COLOR c);
};

#endif
