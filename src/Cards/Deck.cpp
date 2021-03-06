#include "../../include/Cards/Deck.h"

#include "../../include/Cards/Card.h"

#include <cstdlib>
#include <vector>

Deck::Deck(){
  deck.clear();
}

Card* Deck::drawCard(){
  Card *rCard;

  if(this->isEmpty())
    return NULL;

  rCard = deck[deck.size() - 1];
  deck.erase(deck.end() - 1);

  return rCard;
}

bool Deck::removeWound(){
  for(int i = 0; i < (int) deck.size(); i++){
    if(deck[i]->getCardType() == WOUND){
      delete deck[i];
      deck.erase(deck.begin() + i);
      return true;
    }
  }
  return false;
}

bool Deck::isEmpty(){
  return (deck.size() == 0);
}

void Deck::addCardTop(Card* card){
  deck.push_back(card);
}

void Deck::shuffle(){
  const int numSwaps = 500;
  Card* aux;
  int c1, c2;

  for(int i = 0; i < numSwaps; i++){
    c1 = rand()%(deck.size());
    c2 = rand()%(deck.size());

    aux = deck[c1];
    deck[c1] = deck[c2];
    deck[c2] = aux;
  }
}

void Deck::clear(){
  deck.clear();
}

int Deck::getSize(){
  return deck.size();
}
