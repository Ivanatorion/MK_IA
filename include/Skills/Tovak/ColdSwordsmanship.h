#ifndef TVKCOLDSWORD_H
#define TVKCOLDSWORD_H

#include "../Skill.h"

class ColdSwordsmanship : public Skill{
  public:
    ColdSwordsmanship();
    void onPlayed(STATE *s);
};

#endif
