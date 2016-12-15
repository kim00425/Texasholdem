//
//  Host.cpp
//  plama
//
//  Created by 무제 on 2016. 12. 13..
//  Copyright © 2016년 무제. All rights reserved.
//

#include "Host.hpp"
Host::Host()
{
    mDeck.setDeck();
}
Card Host::GiveCard()
{
    return mDeck.DrawCard();
}
