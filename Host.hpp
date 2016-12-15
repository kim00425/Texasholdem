//
//  Host.hpp
//  plama
//
//  Created by 무제 on 2016. 12. 13..
//  Copyright © 2016년 무제. All rights reserved.
//

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
