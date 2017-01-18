#include "Deck.hpp"
int myrandom (int i) { return std::rand()%i;}
Deck::Deck()
{
    for(int i=Suit::Club;i<=Suit::Heart;i++)
    {
        for(int j=Num::Two;j<=Num::Ace;j++)
        {
            Card SetCard(i,j);
            mDeck.push_back(SetCard);
        }
    }
    std::random_shuffle(mDeck.begin(),mDeck.end(),myrandom);
}
Card Deck::DrawCard() const
{
    static int i=0;
    Card temp;
    
    temp=mDeck.at(i);
    i++;

    return temp;
}
void Deck::setDeck()
{
    std::random_shuffle(mDeck.begin(),mDeck.end(),myrandom);
}
void Deck::CardInfo()
{
    for(int i=0;i<52;i++)
    {
        std::cout<<mDeck[i].CardInfo()<<std::endl;
    }
}
