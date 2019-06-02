#ifndef TVKWHONEEDSMAGIC_H
#define TVKWHONEEDSMAGIC_H

#include "../Skill.h"

class WhoNeedsMagic : public Skill{
  public:
    WhoNeedsMagic();
    void onPlayed(STATE *s);
};

#endif
