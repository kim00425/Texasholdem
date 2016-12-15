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
#include"Host.hpp"
#include<iostream>
typedef enum Action{Raise=1,Call,Fold}Action;
using int32=unsigned int;
class Deck;
class Host;
class Player
{
private:
    Hand mHand;
    Action mAction;
    int32 mStack;
    PokerRank mRank;
public:
    Player();
    Player& operator=(const Hand &);
    Player& operator=(const Card &);
    Player& operator=(Host &);
    Match operator>(Player &);
    PokerRank Rank();
    Hand GetHand(){return mHand;}
    int32 GetStack(){return mStack;}
    Action GetAction(){return mAction;}
    void Bet(Action action,int32 & GameStack);
    void PlayerInfo();
};
Match CompareRank(Player &,Player &);
#endif /* Player_hpp */
