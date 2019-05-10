#ifndef DECK_H
#define DECK_H

#include <vector>

class Card;
class Deck{
  public:
    Deck();

    Card* drawCard();               //Removes the top card of the Deck and returns it.
    bool isEmpty();                 //Test if the Deck is empty.
    void addCardTop(Card* card);    //Add a Card on top of the Deck
    void shuffle();                 //Shuffles the Deck
    void clear();                   //Clears the Deck
    int getSize();                  //Returns the ammount of cards in the Deck

  private:
    std::vector<Card*> deck;
};

#endif
