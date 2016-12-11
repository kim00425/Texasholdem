//
//  card.h
//  plama
//
//  Created by 무제 on 2016. 11. 27..
//  Copyright © 2016년 무제. All rights reserved.
//

#ifndef card_h
#define card_h
#include<string>
typedef enum suit{Club,Diamond,Spade,Heart} Suit;
typedef enum num{Two=2,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace} Num;
 
class Card
{
private:
    Suit mSuit;
    Num mNum;
public:
    Card(int cS=0,int cN=2);
    std::string CardInfo();
    Num GetNum(){return mNum;} const
    Suit GetSuit(){return mSuit;} 
    bool operator<(const Card & cCard) const;
    ~Card();
};
#endif /* card_h */
