#include<iostream>
#include<ctime>

#include"card.h"
#include"Hand.hpp"
#include"Deck.hpp"
#include"Player.hpp"
#include"Game.hpp"
#include"Host.hpp"
using namespace std;

int main()
{
    srand((unsigned int)time(0));
    Game game;
    game.make_player(3);
    game.Play();
    game.set_round(FLOP);
    game.Play();
    game.set_round(TURN);
    game.Play();
    game.Winner_Player();
    
    }
