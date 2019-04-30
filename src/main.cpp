#include <cstdio>
#include <vector>
#include "../include/defines.h"
#include "../include/Cards/Card.h"
#include "../include/Cards/ActionCards/ACRage.h"

int main(int argc, char* argv[]){
  Card *c = new ACRage();

  printf("Name: %s", c->getName().c_str());
  return 0;
}
