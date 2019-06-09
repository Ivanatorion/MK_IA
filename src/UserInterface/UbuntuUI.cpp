#ifdef __linux__
#include "../../include/UserInterface/UbuntuUI.h"

#include <cstdio>

UbuntuUI::UbuntuUI(){
  printf("Running on Linux\n");
}

void UbuntuUI::printPlayerHand(STATE *s){
  printf("Cards in hand: ");
  if(s->playerHand.size() == 0)
    printColored("None", RED);
  else
    for(int i = 0; i < s->playerHand.size(); i++){
      if(s->playerHand[i]->getCardType() == WOUND)
        printColored("Wound", BLACK);
      else
        printColored(s->playerHand[i]->getName() + " ", s->playerHand[i]->getColor());
    }
}

void UbuntuUI::printPlayerMana(STATE *s){
  char quant[10];
  printf("Crystals: ");
  sprintf(quant, "%d ", s->playerCrystalsRed);
  printColored(quant, RED);
  sprintf(quant, "%d ", s->playerCrystalsBlue);
  printColored(quant, BLUE);
  sprintf(quant, "%d ", s->playerCrystalsGreen);
  printColored(quant, GREEN);
  sprintf(quant, "%d ", s->playerCrystalsWhite);
  printColored(quant, WHITE);

  printf("\nTokens:   ");
  sprintf(quant, "%d ", s->playerTokensRed);
  printColored(quant, RED);
  sprintf(quant, "%d ", s->playerTokensBlue);
  printColored(quant, BLUE);
  sprintf(quant, "%d ", s->playerTokensGreen);
  printColored(quant, GREEN);
  sprintf(quant, "%d ", s->playerTokensWhite);
  printColored(quant, WHITE);
}

void UbuntuUI::printSource(STATE *s){
  printf("Source: ");
  for(int i = 0; i < N_DICE_IN_SOURCE; i++)
    printColored(colorToString(s->sourceDice[i]) + " ", s->sourceDice[i]);
}

void UbuntuUI::printSpecial(STATE *s){
  printf("Special:\n");

  if(s->ManaDrawWeak)
    printf("Can take extra dice (ManaDraw)\n");
  if(s->ConcentrationStrong)
    printf("Next Strong Card is empowered (Concentration)\n");
  if(s->TovakIDontGiveADamn)
    printf("Next Sideways Card Gives 2/3 of choosen attribute (Tovak IDGAD)\n");
  if(s->IceShieldStrong)
    printf("Next Blocked Enemy gets armor -3 (Ice Shield)\n");
  if(s->FrostBridgeWeak)
    printf("Move cost of Swamps is 1 (Frost Bridge)");
  if(s->FrostBridgeStrong)
    printf("Move cost of Swamps and Lakes is 1 (Frost Bridge)");
  if(s->SongOfWindWeak)
    printf("Move cost of Plains/Deserts/Wastelands reduced by 1 (Song Of Wind)\n");
  if(s->SongOfWindStrong)
    printf("Move cost of Plains/Deserts/Wastelands reduced by 2 (Song Of Wind)\n");
  if(s->SongOfWindStrongBlue)
    printf("Can travel through Lakes (Song Of Wind)\n");
  if(s->PathFindingWeak)
    printf("Move cost of terrains reduced by 1 (Min 2) (Path Finding)\n");
  if(s->PathFindingStrong)
    printf("Move cost of terrains is 2 (Path Finding)\n");
}

void UbuntuUI::printColored(std::string s, COLOR c){
  switch(c){
    case RED:
      printf("\033[0;31m%s\033[0m", s.c_str());
      break;
    case GREEN:
      printf("\033[0;32m%s\033[0m", s.c_str());
      break;
    case BLUE:
      printf("\033[0;34m%s\033[0m", s.c_str());
      break;
    case WHITE:
      printf("\033[1;37m%s\033[0m", s.c_str());
      break;
    case GOLD:
      printf("\033[1;33m%s\033[0m", s.c_str());
      break;
    case BLACK:
      printf("\033[1;30m%s\033[0m", s.c_str());
      break;
    default:
      printf("%s", s.c_str());
      break;
  }
}

void UbuntuUI::printState(STATE state){
  if(!state.gameRunning){
    printf("\nGame is not running\n");
    return;
  }

  printf("\n################################################################################\n");

  switch (state.gameScene) {
    case MOVE_AND_EXPLORE:
      printStateMoveExplore(&state);
      break;
    case BATTLE_BLOCK:
    case BATTLE_ATTACK:
    case BATTLE_RANGED:
    case BATTLE_ASSIGN:
      printStateBattle(&state);
      break;
  }

  printf("\n################################################################################\n");
}

void UbuntuUI::printStateBattle(STATE *s){
  printf("\nIn Battle Phase: ");
  switch (s->gameScene) {
    case BATTLE_RANGED:
      printf("Ranged Attack");
      break;
    case BATTLE_BLOCK:
      printf("Block");
      break;
    case BATTLE_ASSIGN:
      printf("Assign Damage");
      break;
    case BATTLE_ATTACK:
      printf("Attack");
      break;
  }

  printf("\n\n");
  printPlayerHand(s);
  printf("\n\n");

  printf("Cards in Deed Deck: %02d               Units:", s->playerDeedDeck.getSize());
  for(int i = 0; i < s->PlayerUnits.size(); i++)
    printf(" %s", s->PlayerUnits[i]->getName().c_str());

  printf("\nCards in Discard Pile: %02d            Units in offer:", s->playerDiscardDeck.getSize());
  for(int i = 0; i < s->UnitOffer.size(); i++)
    printf(" %s", s->UnitOffer[i]->getName().c_str());

  printSource(s);

    //Attributes
  printf("\n\nAttack: %d\nBlock: %d\nMove: %d\nInfluence: %d", s->avAttack, s->avBlock, s->avMove, s->avInfluence);

  printf("\n\n");
  printPlayerMana(s);
  printf("\n\n");

  switch (s->gameScene) {
    case BATTLE_RANGED:
      printStateBattleRanged(s);
      break;
    case BATTLE_BLOCK:
      printStateBattleBlock(s);
      break;
    case BATTLE_ASSIGN:
      printStateBattleAssing(s);
      break;
    case BATTLE_ATTACK:
      printStateBattleAttack(s);
      break;
  }

  printf("\n\n");

  printSpecial(s);
}

void UbuntuUI::printStateBattleRanged(STATE *s){
  printf("Enemies: {");
  for(int i = 0; i < s->BattleEnemies.size(); i++){
    printf("\n  %s", s->BattleEnemies[i].name.c_str());
    printf("\n    %d Health", s->BattleEnemies[i].health);
  }
  printf("\n}\n\nEnemies Selected: {");
  for(int i = 0; i < s->BattleEnemiesSelected.size(); i++){
    printf("%s", s->BattleEnemiesSelected[i].name.c_str());
    if(i != s->BattleEnemiesSelected.size()-1)
      printf(", ");
  }
  printf("}");
}

void UbuntuUI::printStateBattleBlock(STATE *s){
  printf("Enemies: {");
  for(int i = 0; i < s->BattleEnemies.size(); i++){
    printf("\n  %s", s->BattleEnemies[i].name.c_str());
    for(int j = 0; j < s->BattleEnemies[i].attacks.size(); j++){
      if(s->BattleEnemies[i].attacks[j].blocked)
        printf("\n    Blocked: ");
      else
        printf("\n    UnBlocked: ");
      printf("%d ", s->BattleEnemies[i].attacks[j].attack);
      switch (s->BattleEnemies[i].attacks[j].type) {
        case PHYSICAL:
          printf("Physical");
          break;
        case FIRE:
          printf("Fire");
          break;
        case ICE:
          printf("Ice");
          break;
        case COLDFIRE:
          printf("ColdFire");
          break;
      }
    }
    printf("\n");
  }
  printf("\n}\n\nEnemies Selected: {");
  for(int i = 0; i < s->BattleEnemiesSelected.size(); i++){
    printf("%s", s->BattleEnemiesSelected[i].name.c_str());
    if(i != s->BattleEnemiesSelected.size()-1)
      printf(", ");
  }
  printf("}");
}

void UbuntuUI::printStateBattleAssing(STATE *s){
  printf("Attacks to Assign: ");
  for(int i = 0; i < s->BattleAttacksToAssign.size(); i++){
    if(i != 0)
      printf(", ");
    printf("%d ", s->BattleAttacksToAssign[i].attack);
    switch (s->BattleAttacksToAssign[i].type) {
      case PHYSICAL:
        printf("Physical");
        break;
      case FIRE:
        printf("Fire");
        break;
      case ICE:
        printf("Ice");
        break;
      case COLDFIRE:
        printf("ColdFire");
        break;
    }
  }

  printf("\n\nAttack Selected:");
  for(int i = 0; i < s->BattleAttacksSelected.size(); i++){
    printf(" %d ", s->BattleAttacksSelected[i].attack);
    switch (s->BattleAttacksSelected[i].type) {
      case PHYSICAL:
        printf("Physical");
        break;
      case FIRE:
        printf("Fire");
        break;
      case ICE:
        printf("Ice");
        break;
      case COLDFIRE:
        printf("ColdFire");
        break;
    }
  }
}

void UbuntuUI::printStateBattleAttack(STATE *s){
  printf("Enemies: {");
  for(int i = 0; i < s->BattleEnemies.size(); i++){
    printf("\n  %s", s->BattleEnemies[i].name.c_str());
    printf("\n    %d Health", s->BattleEnemies[i].health);
  }
  printf("\n}\n\nEnemies Selected: {");
  for(int i = 0; i < s->BattleEnemiesSelected.size(); i++){
    printf("%s", s->BattleEnemiesSelected[i].name.c_str());
    if(i != s->BattleEnemiesSelected.size()-1)
      printf(", ");
  }
  printf("}");
}

void UbuntuUI::printStateMoveExplore(STATE *s){
  printf("\n");
  printPlayerHand(s);
  printf("\n\n");

  printf("Cards in Deed Deck: %02d               Units:", s->playerDeedDeck.getSize());
  for(int i = 0; i < s->PlayerUnits.size(); i++)
    printf(" %s", s->PlayerUnits[i]->getName().c_str());

  printf("\nCards in Discard Pile: %02d            Units in offer:", s->playerDiscardDeck.getSize());
  for(int i = 0; i < s->UnitOffer.size(); i++)
    printf(" %s", s->UnitOffer[i]->getName().c_str());

  printf("\nCurrent Round: %d", s->currentRound);

  //Fame
  printf("\nFame: %d\nReputation: %d\n\n", s->playerFame, s->playerReputation);

  printSource(s);

  //Attributes
  printf("\n\nMove: %d\nInfluence: %d\nHeal: %d\n\n", s->avMove, s->avInfluence, s->avHeal);

  //Location on map
  printf("Current map tile: %d\n", s->curTileN);
  printf("Current tile hex: %d\n", s->curHexN);
  printf("Hex Terrain: ");
  switch (s->curHex->terrain) {
    case HILL:
      printf("Hill");
      break;
    case PLAIN:
      printf("Plain");
      break;
    case WASTELAND:
      printf("Wasteland");
      break;
    case SWAMP:
      printf("Swamp");
      break;
    case FOREST:
      printf("Forest");
      break;
    case DESERT:
      printf("Desert");
      break;
  }
  printf("\nHex Location: ");
  switch (s->curHex->location) {
    case NONEL:
      printf("None");
      break;
    case VILLAGE:
      printf("Village");
      break;
    case GLADE:
      printf("Glade");
      break;
    case TOWER:
      printf("Tower");
      break;
    case KEEP:
      printf("Keep");
      break;
    case MONASTERY:
      printf("Monastery");
      break;
    case MINEG:
      printf("Green Mine");
      break;
    case MINEB:
      printf("Blue Mine");
      break;
    case MINER:
      printf("Red Mine");
      break;
    case MINEW:
      printf("White Mine");
      break;
    case ORC:
      printf("Orc (This should not be happening btw)");
      break;
    default:
      printf("Not defined");
  }
  printf("\n\n");

  //Map status
  printf("Map: [");
  for(int i = 0; i < NUM_TILES-1; i++)
    if((s->m->getTile(i).tileN) == -1)
      printf("? ");
    else
      printf("%d ", (s->m->getTile(i).tileN));
  if((s->m->getTile(NUM_TILES-1).tileN) == -1)
    printf("?");
  else
    printf("%d", (s->m->getTile(NUM_TILES-1).tileN));
  printf("]\n");

  printPlayerMana(s);

  printf("\n");

  printSpecial(s);
}

#endif
