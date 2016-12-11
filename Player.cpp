//
//  Player.cpp
//  plama
//
//  Created by 무제 on 2016. 11. 29..
//  Copyright © 2016년 무제. All rights reserved.
//

#include "Player.hpp"
Player::Player()
{
    
}
void Player::PlayerInfo()
{
    mHand.HandInfo();
    std::string rank;
    switch (mRank)
    {
        case StraihtFlush:rank="스트레이트 플러쉬";break;
        case FourKind:rank="포카드";break;
        case FullHouse:rank="풀 하우스";break;
        case Flush:rank="플러쉬";break;
        case Straight:rank="스트레이트";break;
        case ThreeKind:rank="트리플";break;
        case twoPair:rank="투페어";break;
        case onePair:rank="원페어";break;
        default:rank="노페어";break;
    }
    std::cout<<"당신의 카드패는 <"<<rank<<"> 입니다."<<std::endl;
}
Player& Player::operator=(const Hand & ihand)
{
    this->mHand=ihand;
    this->mRank=mHand.Check_Rank();
    return *this;
}
Player& Player::operator=(const Card &icard)
{
    this->mHand=icard;
    this->mRank=mHand.Check_Rank();
    return *this;
}
Player& Player::operator=(const Deck &ideck)
{
    this->mHand=ideck.GiveCard();
    this->mRank=mHand.Check_Rank();
    return *this;
}
PokerRank Player::Rank()
{
    return mHand.Check_Rank();
}
Match Player::operator>(Player & p1)
{
    
    if(this->mRank>p1.mRank)
        return Win;
    else if(this->mRank==p1.mRank)
    {
        Hand h1,h2;
        h1=this->GetHand();
        h2=p1.GetHand();
        Match a=compare(h1, h2);
        return a;
    }
    else
        return Defeat;
    
    
    
}
Match CompareRank(Player & player1,Player &player2)
{
    return player1>player2;
}

