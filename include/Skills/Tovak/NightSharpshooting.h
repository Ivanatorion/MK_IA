#ifndef TVKNGTSPST_H
#define TVKNGTSPST_H

#include "../Skill.h"

class NightSharpshooting : public Skill{
  public:
    NightSharpshooting();
    void onPlayed(STATE *s);
};

#endif
