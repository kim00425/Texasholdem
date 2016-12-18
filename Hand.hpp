//
//  Hand.hpp
//  plama
//
//  Created by 무제 on 2016. 11. 30..
//  Copyright © 2016년 무제. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp
#include"card.h"
#include<vector>
#include<algorithm>
#include<iterator>
#include<iostream>

typedef enum PokerRank{noRank,onePair,twoPair,ThreeKind,Straight,Flush,FullHouse,FourKind,StraihtFlush}PokerRank;
typedef enum Match{Defeat=-1,Win=1,Draw=2} Match;
typedef unsigned u16;
class Hand
{
private:
    std::vector<Card> hand;
public:
    Hand(const Card pCard);
    Hand(){};
    void Sort();
    PokerRank Check_Rank();
    Hand & operator=(const Card & cc);
    Hand & operator=(const Hand & cc);
    std::vector<Card> GetCard(){return hand;}
    void HandInfo();
};

void CheckMade(std::vector<Card> &,std::vector<int> &,std::vector<int> & ,std::vector<int> &);
void BitMade(std::vector<int> & numofhand,std::vector<int> & suitofhand,u16 & num,u16 & suit);
void BitMade(std::vector<int> &,u16 &);

void IsPairOrThreeOrFourKind(std::vector<Card> &,bool & ,bool & ,bool & ,bool &,bool &);
void IsStraightOrFlush(std::vector<int> & NumOfHand,std::vector<int> & SuitOfHand,bool & straight,bool & flush);

Match compare(Hand &,Hand &);

Match comparenopair(std::vector<Card> &,std::vector<Card> &);
Match compareonepair(std::vector<Card> &,std::vector<Card> &);
Match comparetwopair(std::vector<Card> &,std::vector<Card> & );
Match comparethreekind(std::vector<Card> &,std::vector<Card> &);
Match comparestraight(std::vector<Card> &,std::vector<Card> & );
Match compareflush(std::vector<Card> &,std::vector<Card> &);
Match comparefullhouse(std::vector<Card> &,std::vector<Card> &);
Match comparefourkind(std::vector<Card> &,std::vector<Card> &);
Match comparestraightflush(std::vector<Card> &,std::vector<Card> &);

#endif /* Hand_hpp */
