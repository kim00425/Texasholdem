//
//  Player.hpp
//  plama
//
//  Created by 무제 on 2016. 11. 29..
//  Copyright © 2016년 무제. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#include"card.h"
#include"Hand.hpp"
#include"Deck.hpp"
#include<iostream>
typedef enum Action{Raise,Call,Fold}Action;
class Deck;
class Player
{
private:
    Hand mHand;
    Action mAction;
    unsigned int money;
    PokerRank mRank;
public:
    Player();
    Player& operator=(const Hand &);
    Player& operator=(const Card &);
    Player& operator=(const Deck &);
    Match operator>(Player &);
    PokerRank Rank();
    Hand GetHand(){return mHand;}
    void PlayerInfo();
};
Match CompareRank(Player &,Player &);
#endif /* Player_hpp */
