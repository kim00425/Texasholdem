//
//  Deck.hpp
//  plama
//
//  Created by 무제 on 2016. 11. 29..
//  Copyright © 2016년 무제. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp
#include "card.h"
#include"Player.hpp"
#include<vector>
#include<iostream>
class Player;

class Deck
{
private:
    std::vector<Card> mDeck;
public:
    Deck();
    void setDeck();
    void CardInfo();
    Card  GiveCard()const;
    ~Deck(){};
    
};
#endif /* Deck_hpp */
