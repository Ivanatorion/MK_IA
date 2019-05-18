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

    //Runs the game main loop.
    void run();

    //Prints information about the current state.
    void printState();

    std::string colorToString(COLOR c);

  private:
    STATE state;

    void reset();

    void shuffleUnits(); //Shuffle the Regular and Elite Units Deck

    void stepUseCardWeak(int actionParam);
    void stepUseCardStrong(int actionParam);
    void stepUseCardSideways(int actionParam);
    void stepUseUnit(int actionParam);
    void stepTakeDieFromSource(int actionParam);
    void stepEndTurn(int actionParam);
    void stepMoveToHex(int actionParam);
    void stepRecruitUnit(int actionParam);
    void stepRevealTile(int actionParam);

    void rollSourceDie(int dieN);
};

#endif
