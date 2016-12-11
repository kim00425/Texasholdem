//
//  card.cpp
//  plama
//
//  Created by 무제 on 2016. 11. 27..
//  Copyright © 2016년 무제. All rights reserved.
//

#include "card.h"


Card::Card(int cS,int cN)
{
    mSuit=static_cast<Suit>(cS);
    mNum=static_cast<Num>(cN);
}
std::string Card::CardInfo() // About card(num,suit)
{
    std::string su;
    std::string nu;
    switch (this->mSuit)
    {
        case suit::Club: su="C"; break;
        case suit::Diamond: su="D"; break;
        case suit::Heart: su="H"; break;
        case suit::Spade: su="S"; break;
        default:break;
    }
    switch (this->mNum)
    {
        
        case num::Two: nu="2"; break;
        case num::Three: nu="3"; break;
        case num::Four: nu="4"; break;
        case num::Five: nu="5"; break;
        case num::Six: nu="6"; break;
        case num::Seven: nu="7"; break;
        case num::Eight: nu="8"; break;
        case num::Nine: nu="9"; break;
        case num::Ten: nu="10"; break;
        case num::Jack: nu="J"; break;
        case num::Queen: nu="Q"; break;
        case num::King: nu="K"; break;
        case num::Ace: nu="A"; break;
        default:break;
    }
    su+=",";
    su+=nu;
    return su;
}
bool Card::operator<(const Card & cCard) const // operator for sorting 
{
    return this->mNum <cCard.mNum;
}
Card::~Card()
{
    
}

