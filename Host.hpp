#ifndef Host_hpp
#define Host_hpp
#include "Deck.hpp"


class Deck;
class Host
{
private:
    Deck mDeck;
public:
    Host();
    Card GiveCard();
};



#endif /* Host_hpp */
