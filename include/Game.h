#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Cards/Card.h"
#include "Cards/Deck.h"
#include "Map.h"
#include "defines.h"
#include "Player/Player.h"

class Game{
  public:
    Game(Player *player);

    //The "step" function makes the game "state" transition based on input "action/actionParam".
    void step(ACTION action, int actionParam);

    //Runs the game.
    void run();

    //Prints information about the current state.
    void printState();

  private:
    STATE state;
    Player *player;

    void reset();
};

#endif
