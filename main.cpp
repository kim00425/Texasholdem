#include<iostream>
#include<ctime>
#include<algorithm>
#include"card.h"
#include"Hand.hpp"
#include"Deck.hpp"
#include"Player.hpp"
#include<iterator>
using namespace std;

int main()
{
    srand((unsigned int)time(0));
    Player p1,p2;
    Deck deck;
        for(int i=0;i<7;i++)
        {
            p1=deck;
            p2=deck;
        }
    p1.PlayerInfo();
    cout<<endl;
    p2.PlayerInfo();
    Match a=CompareRank(p1, p2);
    cout<<a<<endl;
}
