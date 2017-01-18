#ifndef Deck_hpp
#define Deck_hpp
#include "card.h"
#include<vector>
#include<iostream>
#include<algorithm>
class Deck
{
private:
    std::vector<Card> mDeck;
public:
    Deck();
    void setDeck();
    void CardInfo();
    Card DrawCard()const;
    ~Deck(){};
    
};
#endif /* Deck_hpp */
