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

    std::string colorToString(COLOR c);

  private:
    STATE state;

    void reset();

    void stepUseCardWeak(int actionParam);
    void stepUseCardStrong(int actionParam);
    void stepTakeDieFromSource(int actionParam);
    void stepEndTurn(int actionParam);

    void rollSourceDie(int dieN);
};

#endif
