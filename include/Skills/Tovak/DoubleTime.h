#ifndef TVKDOUBLETIME_H
#define TVKDOUBLETIME_H

#include "../Skill.h"

class DoubleTime : public Skill{
  public:
    DoubleTime();
    void onPlayed(STATE *s);
};

#endif
