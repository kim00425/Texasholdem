#ifndef Game_hpp
#define Game_hpp
#include "card.h"
#include "Hand.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Host.hpp"
typedef enum Round{PRE_FLOP,FLOP,TURN,RIVER}Round;

class Game
{
    
private:
    std::vector<Player> mPlayer;
    std::vector<Card> FiveDraw;
    std::vector<Player*> wPlayer;
    Host host;
    int32 SumStack;
    int32 RaiseStack;
    Round round;
public:
    Game();
    void set_round(Round r);
    void make_player(int player);
    void Play();
    void Show_player();
   
    
    Game & operator=(const Player & client_player);
};


#endif /* Game_hpp */
