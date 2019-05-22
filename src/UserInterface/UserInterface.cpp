#include "../../include/UserInterface/UserInterface.h"

std::string UserInterface::colorToString(COLOR c){
  switch (c) {
    case RED:
      return "Red";
    case BLUE:
      return "Blue";
    case GREEN:
      return "Green";
    case WHITE:
      return "White";
    case GOLD:
      return "Gold";
    case BLACK:
      return "Black";
    default:
      return "None";
  }
}
