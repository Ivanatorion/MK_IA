#ifndef ACSWIFTNESS_H
#define ACSWIFTNESS_H

#include <string>
#include "../Card.h"

class ACSwiftness : public Card{
  public:
    ACSwiftness();
    void playCardWeak(STATE *s);
    void playCardStrong(STATE *s);
    std::string getName();

  private:

};

#endif
