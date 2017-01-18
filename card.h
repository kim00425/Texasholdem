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
    Card(const Card &);
    std::string CardInfo();
    Num GetNum(){return mNum;} const
    Suit GetSuit(){return mSuit;}
    Card GetCard(){return *this;};
    bool operator<(const Card & cCard) const;
};
#endif /* card_h */
