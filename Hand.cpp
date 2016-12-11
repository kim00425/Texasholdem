//
//  Hand.cpp
//  plama
//
//  Created by 무제 on 2016. 11. 30..
//  Copyright © 2016년 무제. All rights reserved.
//

#include "Hand.hpp"
#include <iostream>

Hand::Hand(const Card pCard)
{
    hand.push_back(pCard);
}

Hand & Hand::operator=(const Card & cc)
{
    hand.push_back(cc);
    return *this;
}
Hand & Hand::operator=(const Hand & cc)
{
    for(int i=0;i< cc.hand.size();i++)
    {
        this->hand.push_back(cc.hand[i]);
    }
    return *this;
}

void Hand::Sort()
{
    sort(hand.begin(),hand.end());
    for(int i=0;i<(int)hand.size();i++)
    {
        std::cout<<hand[i].CardInfo()<<std::endl;
    }
}
void Hand::HandInfo()
{
    for(int i=0;i<hand.size();i++)
    {
        std::cout<<hand[i].CardInfo()<<std::endl;
    }
    
    
}
void CheckMade
(std::vector<Card> & cHand,std::vector<int> & AllNum,std::vector<int> & UniquedCard,std::vector<int> & SuitCard)
{
    
    for(int i=0;i<cHand.size();i++)
    {
        UniquedCard.push_back(cHand[i].GetNum());
        SuitCard.push_back(cHand[i].GetSuit());
    }
    sort(UniquedCard.begin(),UniquedCard.end());
    sort(SuitCard.begin(),SuitCard.end());
    UniquedCard.erase(unique(UniquedCard.begin(),UniquedCard.end()), UniquedCard.end());
    for(int i=0;i<cHand.size();i++)
    {
        AllNum.push_back(cHand[i].GetNum());
    }
    
}
void BitMade(std::vector<int> & numofhand,std::vector<int> & suitofhand,u16 & num,u16 & suit)
{
    for(int i=0;i<numofhand.size();i++)
    {
        num|=1<<numofhand[i];
        if(numofhand[i]==Num::Ace)
            num+=2;
    }
    
    for(int i=0;i<suitofhand.size();i++)
    {
        if(suitofhand[i]==suitofhand[i+1])
        {
            suit+=1;
            suit<<=1;
        }
        else
            suit<<=1;
    }
    
}
void BitMade(std::vector<int> & numofhand,u16 & num)
{
    for(int i=0;i<numofhand.size();i++)
    {
        num|=1<<numofhand[i];
    }
}

void IsPairOrThreeOrFourKind
(std::vector<int> & cHand,std::vector<int> & UniqueOfcHand,bool & onePair,bool & twoPair,bool & Three,bool & fourKind,bool & fullhouse)
{
    onePair=twoPair=Three=fourKind=fullhouse=false;
    int cnt=0;
    int checkPair=0;
    
    for(int i=0;i<UniqueOfcHand.size();i++)
    {
        cnt=(int)std::count(cHand.begin(),cHand.end(),UniqueOfcHand[i]);
        if(cnt==2)
        {
            ++checkPair;
            onePair=true;
        }
        if(cnt==3){Three=true;}
        if(cnt==4){fourKind=true;}
    }
    if(checkPair==2){twoPair=true;}
    if(onePair==true&&Three==true){fullhouse=true;}
    
}
void IsStraightOrFlush(std::vector<int> & NumOfHand,std::vector<int> & SuitOfHand,bool & straight,bool & flush)
{
    straight=flush=false;
    u16 numchecker=0;
    u16 suitchecker=0;
    BitMade(NumOfHand, SuitOfHand, numchecker, suitchecker);
    
    for(int i=0;i<10;numchecker>>=1,i++)
    {
        if((numchecker&0b11111)==0b11111){straight=true;}
        
    }
    for(int i=0;i<14;suitchecker>>=1,i++)
    {
        if((suitchecker&0b1111)==0b1111){flush=true;}
    }
}
Match compare(Hand & h1,Hand & h2)
{
    std::vector<Card> hand1=h1.GetCard();
    std::vector<Card> hand2=h2.GetCard();
    PokerRank compare=h1.Check_Rank();
        switch (compare) {
            case noRank:
                return comparenopair(hand1, hand2);
                break;
            case onePair:
                return compareonepair(hand1, hand2);
                break;
            case twoPair:
                return comparetwopair(hand1, hand2);
                break;
            case ThreeKind:
                return comparethreekind(hand1, hand2);
                break;
            case Straight:
                return comparestraight(hand1, hand2);
                break;
            case Flush:
                return compareflush(hand1, hand2);
                break;
            case FullHouse:
                return comparefullhouse(hand1, hand2);
                break;
            case FourKind:
                return comparefourkind(hand1, hand2);
                break;
            case StraihtFlush:
                return comparestraightflush(hand1, hand2);
                break;
            default:
                std::cout<<"I Can't Comepare!! Plaese Debug(From Hand.cpp)"<<std::endl;
                break;
        }
}
Match comparenopair(std::vector<Card> & hand1,std::vector<Card> & hand2)
{
    u16 a,b;
    a=b=0;
    
    for(int i=0;i<7;i++)
    {
        a|=1<<hand1[i].GetNum();
        b|=1<<hand1[i].GetNum();
    }
    if(a>b) return Win;
    else if(a==b) return Draw;
    else
        return Defeat;
}

Match compareonepair(std::vector<Card> & hand1,std::vector<Card> & hand2)
{
    std::vector<int> numofcards1;
    std::vector<int> numofcards2;
    u16 a,b;
    a=b=0;
    int cnt,cnt2;
    for(int i=0;i<7;i++)
    {
        numofcards1.push_back(hand1[i].GetNum());
        numofcards2.push_back(hand2[i].GetNum());
    }
    for(int i=0;i<7;i++)
    {
        cnt=(int)std::count(numofcards1.begin(),numofcards1.end(),hand1[i].GetNum());
        if(cnt==2)
        {
            a|=1<<hand1[i].GetNum();
        }
        
        cnt2=(int)std::count(numofcards2.begin(),numofcards2.end(),hand2[i].GetNum());
        if(cnt2==2)
        {
            b|=1<<hand2[i].GetNum();
        }
    }
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    if(a>b)
        return Win;
    else if(a==b)
    {
        for(int i=0;i<7;i++)
        {
            a|=1<<hand1[i].GetNum();
            b|=1<<hand2[i].GetNum();
        }
        if(a>b) return Win;
        else if(a==b) return Draw;
        else
            return Defeat;
    }
    else
        return Defeat;
    
    
}
Match comparetwopair(std::vector<Card> & hand1,std::vector<Card> & hand2)
{
    std::vector<int> numofcards1;
    std::vector<int> numofcards2;
    u16 a,b;
    a=b=0;
    int cnt=0;

    for(int i=0;i<7;i++)
    {
        numofcards1.push_back(hand1[i].GetNum());
        numofcards2.push_back(hand2[i].GetNum());
    }
    for(int i=0;i<7;i++)
    {
        cnt=(int)std::count(numofcards1.begin(),numofcards1.end(),hand1[i].GetNum());
        if(cnt==2)
        {
            a|=1<<hand1[i].GetNum();
        }
    }
    for(int i=0;i<7;i++)
    {
        cnt=(int)std::count(numofcards2.begin(),numofcards2.end(),hand2[i].GetNum());
        if(cnt==2)
        {
            b|=1<<hand2[i].GetNum();
        }
    }
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    
    if(a>b)
        return Win;
    else if(a==b)
    {
        for(int i=0;i<7;i++)
        {
            a|=1<<hand1[i].GetNum();
            b|=1<<hand2[i].GetNum();
        }
        if(a>b) return Win;
        else if(a==b) return Draw;
        else
            return Defeat;
    }
    else
        return Defeat;
    
}
Match comparethreekind(std::vector<Card> & hand1,std::vector<Card> & hand2)
{
    std::vector<int> numofcards1;
    std::vector<int> numofcards2;
    u16 a ,b;
    int cnt=0;
    
    for(int i=0;i<7;i++)
    {
        numofcards1.push_back(hand1[i].GetNum());
        numofcards2.push_back(hand2[i].GetNum());
    }
    for(int i=0;i<7;i++)
    {
        cnt=(int)std::count(numofcards1.begin(),numofcards1.end(),hand1[i].GetNum());
        
        if(cnt==3)
        {
            a|=1<<hand1[i].GetNum();
        }
        cnt=(int)std::count(numofcards2.begin(),numofcards2.end(),hand2[i].GetNum());
        if(cnt==3)
        {
            b|=1<<hand2[i].GetNum();
        }
    }
    
    if(a>b)
        return Win;
    else
        return Defeat;
}
Match comparestraight(std::vector<Card> & hand1,std::vector<Card> & hand2)
{
    std::vector<Num> numofcards1;
    std::vector<Num> numofcards2;
    u16 a,b;
    u16 checker=0b11111;
    u16 Ace_checker=0b10000000111110;
    
    for(int i=0;i<7;i++)
    {
        numofcards1.push_back(hand1[i].GetNum());
        numofcards2.push_back(hand2[i].GetNum());
    }
    for(int i=0;i<7;i++)
    {
        a|=1<<hand1[i].GetNum();
        b|=1<<hand2[i].GetNum();
    }
    if((a&Ace_checker)==Ace_checker)
    {
        a&=Ace_checker;
    }
    if((b&Ace_checker)==Ace_checker)
    {
        b&=Ace_checker;
    }
    for(int i=0;i<10;checker<<=1,i++)
    {
        if((a&checker)==checker)
        {
            a&=checker;
        }
        if((b&checker)==checker)
        {
            b&=checker;
        }
    }
    if(a>b)
        return Win;
    else if(a==b)
    {
        for(int i=0;i<7;i++)
        {
            a|=1<<hand1[i].GetNum();
            b|=1<<hand2[i].GetNum();
        }
        if(a>b) return Win;
        else if(a==b) return Draw;
        else
            return Defeat;
    }
    else
        return Defeat;
    
}

Match compareflush(std::vector<Card> & hand1,std::vector<Card> & hand2)
{
    u16 a,b;
    
    for(int i=0;i<7;i++)
    {
        a|=1<<hand1[i].GetNum();
        b|=1<<hand1[i].GetNum();
    }
    if(a>b) return Win;
    else if(a==b) return Draw;
    else
        return Defeat;
}

Match comparefullhouse(std::vector<Card> & hand1,std::vector<Card> & hand2)
{
    std::vector<int> numofcards1;
    std::vector<int> numofcards2;
    u16 a,b;
    int cnt=0;
    
    for(int i=0;i<7;i++)
    {
        numofcards1.push_back(hand1[i].GetNum());
        numofcards2.push_back(hand2[i].GetNum());
    }
    for(int i=0;i<7;i++)
    {
        cnt=(int)std::count(numofcards1.begin(),numofcards1.end(),hand1[i].GetNum());
        if(cnt==3)
        {
            a|=1<<hand1[i].GetNum();
        }
    }
    for(int i=0;i<7;i++)
    {
        cnt=(int)std::count(numofcards2.begin(),numofcards2.end(),hand2[i].GetNum());
        if(cnt==3)
        {
            b|=1<<hand2[i].GetNum();
        }
    }
    if(a>b)
        return Win;
    else
        return Defeat;
}

Match comparefourkind(std::vector<Card> & hand1,std::vector<Card> & hand2)
{
    std::vector<int> numofcards1;
    std::vector<int> numofcards2;
    u16 a ,b;
    int cnt=0;
    
    for(int i=0;i<7;i++)
    {
        numofcards1.push_back(hand1[i].GetNum());
        numofcards2.push_back(hand2[i].GetNum());
    }
    for(int i=0;i<7;i++)
    {
        cnt=(int)std::count(numofcards1.begin(),numofcards1.end(),hand1[i].GetNum());
        if(cnt==4)
        {
            a|=1<<hand1[i].GetNum();
        }
        cnt=(int)std::count(numofcards2.begin(),numofcards2.end(),hand2[i].GetNum());
        if(cnt==4)
        {
            b|=1<<hand2[i].GetNum();
        }
    }
    if(a>b)
        return Win;
    else
        return Defeat;
}

Match comparestraightflush(std::vector<Card> & hand1,std::vector<Card> & hand2)
{
    return comparestraight(hand1, hand2);
}

PokerRank Hand::Check_Rank()
{
    bool onepair,twopair,three,straight,flush,fullhouse,fourkind;
    
    u16 num,suit;
    std::vector<int> uniqueofcards;
    std::vector<int> suitofcards;
    std::vector<int> numofhand;
    
    CheckMade(this->hand,numofhand,uniqueofcards,suitofcards);
    
    
    BitMade(numofhand, suitofcards, num, suit);
    IsPairOrThreeOrFourKind(numofhand, uniqueofcards, onepair, twopair, three, fourkind, fullhouse);
    IsStraightOrFlush(numofhand, suitofcards, straight, flush);
    
    if(flush&&straight){return StraihtFlush;}
    else if(fourkind){return FourKind;}
    else if(fullhouse){return FullHouse;}
    else if(flush){return Flush;}
    else if(straight){return Straight;}
    else if(three){return ThreeKind;}
    else if(twopair){return twoPair;}
    else if(onepair){return onePair;}
    else return noRank;
}



    
