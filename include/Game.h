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

    //The "step" function makes the game "state" transition based on input "action/actionParam"
    void step(ACTION action, int actionParam);

    //Runs the game main loop
    void run();

    //Prints information about the current State
    void printState();

    std::string colorToString(COLOR c);

  private:
    STATE state;

    void resetGame();
    void resetRound();

    void shuffleUnits(); //Shuffle the Regular and Elite Units Deck

    void clearStateAvs();

    void stepUseCardWeak(int actionParam);
    void stepUseCardStrong(int actionParam);
    void stepUseCardSideways(int actionParam);
    void stepUseUnit(int actionParam);
    void stepTakeDieFromSource(int actionParam);
    void stepEndTurn(int actionParam);
    void stepMoveToHex(int actionParam);
    void stepRecruitUnit(int actionParam);
    void stepRevealTile(int actionParam);
    void stepAttackRampagingEnemy(int actionParam);

    void stepSelectEnemy(int actionParam);
    void stepSelectAttackToAssign(int actionParam);
    void stepAttackSelectedEnemies(int actionParam);
    void stepBlockEnemy(int actionParam);
    void stepAssingDamagePlayer(int actionParam);
    void stepAssingDamageUnit(int actionParam);
    void stepAdvanceBattlePhase(int actionParam);

    void printStateBattle();
    void printStateBattleRanged();
    void printStateBattleBlock();
    void printStateBattleAssing();
    void printStateBattleAttack();
    void printStateMoveExplore();

    void rollSourceDie(int dieN);
};

#endif
