//2017. 01. 18.
//Game클래스 Play()부분 Bet에서 코딩 시작해야함 -> 중간에 Raise 베팅이 나와도 전부 베팅하면 다음 라운드로 넘어감
//Game클래스 승자비교하는 함수 안 만듬 -> 베팅 중에 Fold 할 때 제외시키는 부분, 마지막 TURN에서 카드 비교해서 이기는 사람 Stack 다 가져가기

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
    Game game;
    game.make_player(3);
    game.Play();
    game.set_round(FLOP);
    game.Play();
    game.set_round(TURN);
    game.Play();
    
    
}
