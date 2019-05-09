#ifndef ACRAGE_H
#define ACRAGE_H

#include <string>
#include "../Card.h"

class ACRage : public Card{
  public:
    ACRage();
    void playCardWeak(STATE *s);
    void playCardStrong(STATE *s);
    std::string getName();
  private:

};

#endif
