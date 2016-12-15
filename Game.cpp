//
//  Game.cpp
//  plama
//
//  Created by 무제 on 2016. 12. 13..
//  Copyright © 2016년 무제. All rights reserved.
//

#include "Game.hpp"
Game::Game():round(PRE_FLOP),Stack(1000)
{
    
}
void Game::set_round(Round r)
{
    round=r;
    if(round==FLOP)
    {
        for(int i=0;i<3;i++)
        {
            FiveDraw.push_back(host.GiveCard());
            for(int j=0;j<mPlayer.size();j++)
            {
                mPlayer[j]=FiveDraw[i];
            }
        }
    }
    else if(round==TURN)
    {
        FiveDraw.push_back(host.GiveCard());
        for(int j=0;j<mPlayer.size();j++)
        {
            mPlayer[j]=FiveDraw[3];
        }
    }
    else if(round==RIVER)
    {
        FiveDraw.push_back(host.GiveCard());
        for(int j=0;j<mPlayer.size();j++)
        {
            mPlayer[j]=FiveDraw[4];
        }
    }
    else
        FiveDraw.clear();
}
void Game::make_player(int i)
{
    for(int j=0;j<i;j++)
    {
        mPlayer.push_back(*new Player());
        mPlayer[j]=host.GiveCard();
        mPlayer[j]=host.GiveCard();
    }
}
void Game::Show_player()
{
    for(int i=0;i<mPlayer.size();i++)
    {
        mPlayer[i].PlayerInfo();
    }
}
void Game::Play()
{
    int action;
    for(int i=0;i<mPlayer.size();i++)
    {
        action=Check_Action(mPlayer[i]);
        if(action==Fold) continue;
        std::cout<<"Yours Card"<<std::endl;
        mPlayer[i].PlayerInfo();
        std::cout<<"Yours Stack:"<<mPlayer[i].GetStack()<<std::endl;
        std::cout<<"Are you Bet?(1=Raise,2=Call,3=Fold):";
        std::cin>>action;
        mPlayer[i].Bet(static_cast<Action>(action), Stack);
        std::cout<<"Your Stack:"<<mPlayer[i].GetStack()<<std::endl;
        std::cout<<std::endl;
    }
}
void Game::winner_player()
{
    for(int i=0;i<mPlayer.size();i++)
    {
        CompareRank(mPlayer[i], mPlayer[i+1]);
    }
}
Action Game::Check_Action(Player p1)
{
    return p1.GetAction();
}
