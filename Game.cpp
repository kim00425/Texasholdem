

#include"Game.hpp"
Game::Game():SumStack(0),round(PRE_FLOP)
{
    std::cout<<"How much pot for Buy-In?:";
    std::cin>>RaiseStack;
    std::cout<<std::endl;
    Host host;
    
}
void Game::make_player(int cnt_player)
{
    for(auto i=0;i<cnt_player;i++)
    {
        mPlayer.push_back(Player());
    }
    for(auto i=0;i<mPlayer.size();i++)
    {
        mPlayer[i]=host.GiveCard();
        mPlayer[i]=host.GiveCard();
    }
}
void Game::set_round(Round r)
{
    this->round=r;
    if(this->round==FLOP)
    {
        std::cout<<"\nFLOP!!";
        Card FLOP1=host.GiveCard();
        Card FLOP2=host.GiveCard();
        Card FLOP3=host.GiveCard();
        for(auto i=0;i<mPlayer.size();i++)
        {
            mPlayer[i]=FLOP1;
            mPlayer[i]=FLOP2;
            mPlayer[i]=FLOP3;
        }
    }
    else if(this->round==TURN)
    {
        std::cout<<"\nTURN!!";
        Card TURN=host.GiveCard();
        for(auto i=0;i<mPlayer.size();i++)
        {
            mPlayer[i]=TURN;
        }
    }
    else if(this->round==RIVER)
    {
        std::cout<<"\nRIVER!!";
        Card RIVER=host.GiveCard();
        for(auto i=0;i<mPlayer.size();i++)
        {
            mPlayer[i]=RIVER;
        }
    }
}
void Game::Play()
{
    int action;
    
    for(auto i=mPlayer.begin();i<mPlayer.end();i++)
    {
        if(i->GetAction()==Fold)
        {
            i++;
            continue;
        }
        std::cout<<"\n["<<i->GetName()<<"'s Info]"<<std::endl;
        std::cout<<"Card:";
        i->PlayerFullInfo();
    
        std::cout<<"Raise Stack:"<<this->RaiseStack;
        std::cout<<"\nWhat do you gonna do?\nAll-in:1 Raise:2\nCall:3 Fold:4\nChoice:";
        while(std::cin>>action)
        {
            if((Action)action<Action::Allin||(Action)action>Action::Fold)
            {
                std::cout<<"You must choice 1~4!!\nChoice:";
                continue;
            }
                break;
        }
        this->SumStack+=i->Bet((Action)action, this->RaiseStack);
    }
}
Game & Game::operator=(const Player & client_player)
{
    mPlayer.push_back(client_player);
    return *this;
}

