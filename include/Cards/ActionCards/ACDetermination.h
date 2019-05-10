#ifndef ACDETERMINATION_H
#define ACDETERMINATION_H

#include <string>
#include "../Card.h"

class ACDetermination : public Card{
  public:
    ACDetermination();
    void playCardWeak(STATE *s);
    void playCardStrong(STATE *s);
    std::string getName();

  private:

};

#endif
