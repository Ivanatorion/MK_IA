#ifndef ACSTAMINA_H
#define ACSTAMINA_H

#include <string>
#include "../Card.h"

class ACStamina : public Card{
  public:
    ACStamina();
    void playCardWeak(STATE *s);
    void playCardStrong(STATE *s);
    std::string getName();

  private:

};

#endif
