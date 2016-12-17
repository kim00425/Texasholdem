//
//  Game.cpp
//  plama
//
//  Created by 무제 on 2016. 12. 13..
//  Copyright © 2016년 무제. All rights reserved.
//

#include "Game.hpp"
Game::Game():round(PRE_FLOP)
{
    std::cout<<"How much pot for Buy-In?:";std::cin>>RaiseStack;
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
    int action=0;
    for(int i=0;i<mPlayer.size();i++)
    {
        action=Check_Action(mPlayer[i]);
        if(action==Fold||mPlayer[i].GetAction()==Allin)
            continue;
        
        std::cout<<mPlayer[i].GetName()<<" Player Card"<<std::endl;
        mPlayer[i].PlayerInfo();
        std::cout<<"Yours Stack:"<<mPlayer[i].GetStack()<<std::endl;
        std::cout<<"Call Pot:"<<RaiseStack<<std::endl;
        std::cout<<"Are you Bet?(1=All-In,2=Raise,3=Call,4=Fold):";
        std::cin>>action;
        SumStack+=mPlayer[i].Bet(static_cast<Action>(action),RaiseStack);
        std::cout<<"Your Stack:"<<mPlayer[i].GetStack()<<std::endl;
        std::cout<<std::endl;
    }
}
void Game::Winner_Player()
{
    for(int i=0;i<mPlayer.size();i++)
    {
        if(mPlayer[i].GetAction()!=Fold)
            wPlayer.push_back(&mPlayer[i]);
    }
    sort(wPlayer.begin(),wPlayer.end());
    std::cout<<"승자:"<<wPlayer[0]->GetName()<<std::endl;
    std::cout<<"핸드:"<<std::endl;
    wPlayer[0]->PlayerInfo();
}
Action Game::Check_Action(Player p1)
{
    return p1.GetAction();
}
