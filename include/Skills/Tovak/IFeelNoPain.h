#ifndef TVKIFNP_H
#define TVKIFNP_H

#include "../Skill.h"

class IFeelNoPain : public Skill{
  public:
    IFeelNoPain();
    void onPlayed(STATE *s);
};

#endif
