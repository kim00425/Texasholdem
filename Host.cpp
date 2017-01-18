#include "Host.hpp"
Host::Host()
{
    mDeck.setDeck();
}
Card Host::GiveCard()
{
    return mDeck.DrawCard();
}
