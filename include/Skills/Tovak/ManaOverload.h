#ifndef TVKMANAOVERLOAD_H
#define TVKMANAOVERLOAD_H

#include "../Skill.h"

class ManaOverload : public Skill{
  public:
    ManaOverload();
    void onPlayed(STATE *s);
};

#endif
