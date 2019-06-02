#ifndef TVKRESBREAK_H
#define TVKRESBREAK_H

#include "../Skill.h"

class ResistanceBreak : public Skill{
  public:
    ResistanceBreak();
    void onPlayed(STATE *s);
};

#endif
