#include "../include/Game.h"

Game::Game(){
  state.m = new Map();

  state.exp = 0;
  state.handMaxSize = 5;
  state.avAttack = 0;
  state.avBlock = 0;
  state.avMove = 0;
  state.avInfluence = 0;
}

void Game::step(ACTION action, int actionParam){
  switch (action) {
    case NOTHING:
      return;
    default:
      return;
  }
}
