#ifndef Player_hpp
#define Player_hpp
#include"card.h"
#include"Hand.hpp"
#include"Deck.hpp"
#include"Host.hpp"
#include<iostream>
typedef enum Action{Allin=1,Raise,Call,Fold}Action;
typedef unsigned int int32;
class Deck;
class Host;
class Player
{
private:
    Hand mHand;
    Action mAction;
    int32 mStack;
    PokerRank mRank;
    std::string mName;
public:
    Player();
    Player& operator=(const Hand &);
    Player& operator=(const Card &);
    Player& operator=(Host &);
    bool operator<(const Player &);
    Match operator==(Player &);
    
    //Player's possible Action list
    PokerRank Rank();                            //Check current Madestate
    int32 Bet(Action action,int32 & raisestack); //Bet
    
    //Get PlayerInformation and used Information
    void PlayerHandInfo();                   //Show HandInfo
    void PlayerFullInfo();                   //Show FullInfo
    
    Hand GetHand(){return mHand;}        //Get info
    int32 GetStack(){return mStack;}     //Get info
    Action GetAction(){return mAction;}  //Get info
    std::string GetName(){return mName;} //Get info
    
};
#endif /* Player_hpp */
