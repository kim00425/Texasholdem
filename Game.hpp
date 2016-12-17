//
//  Game.hpp
//  plama
//
//  Created by 무제 on 2016. 12. 13..
//  Copyright © 2016년 무제. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "card.h"
#include "Hand.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Host.hpp"
typedef enum Round{PRE_FLOP,FLOP,TURN,RIVER}Round;

class Game
{
    
private:
    std::vector<Player> mPlayer;
    std::vector<Card> FiveDraw;
    std::vector<Player*> wPlayer;
    Host host;
    int32 SumStack;
    int32 RaiseStack;
    Round round;
public:
    Game();
    void set_round(Round r);
    void make_player(int i);
    void Play();
    void Show_player();
    Action Check_Action(Player);
    void Winner_Player();
};


#endif /* Game_hpp */
