#include "../../../include/Skills/Tovak/ResistanceBreak.h"

#include "../../../include/Player/Player.h"

ResistanceBreak::ResistanceBreak(){
  this->name = "ResistanceBreak";
  this->cooldown = ONCE_A_TURN;
}

void ResistanceBreak::onPlayed(STATE *s){
  if(s->gameScene != BATTLE_RANGED && s->gameScene != BATTLE_ATTACK)
    return;

  std::vector<std::string> choices;
  for(int i = 0; i < (int) s->BattleEnemies.size(); i++)
    choices.push_back(s->BattleEnemies[i].name);
  for(int i = 0; i < (int) s->BattleEnemiesSelected.size(); i++)
    choices.push_back(s->BattleEnemiesSelected[i].name);

	int choice = s->player->chooseOption(choices);

  if(choice >= (int) s->BattleEnemies.size()){
    choice = choice - s->BattleEnemies.size();
    if(s->BattleEnemiesSelected[choice].pRes)
      s->BattleEnemiesSelected[choice].health--;
    if(s->BattleEnemiesSelected[choice].fRes)
      s->BattleEnemiesSelected[choice].health--;
    if(s->BattleEnemiesSelected[choice].iRes)
      s->BattleEnemiesSelected[choice].health--;
    if(s->BattleEnemiesSelected[choice].health < 1)
      s->BattleEnemiesSelected[choice].health = 1;
  }
  else{
    if(s->BattleEnemies[choice].pRes)
      s->BattleEnemies[choice].health--;
    if(s->BattleEnemies[choice].fRes)
      s->BattleEnemies[choice].health--;
    if(s->BattleEnemies[choice].iRes)
      s->BattleEnemies[choice].health--;
    if(s->BattleEnemies[choice].health < 1)
      s->BattleEnemies[choice].health = 1;
  }
}
