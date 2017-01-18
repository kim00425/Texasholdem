#include "Player.hpp"
Player::Player()
{
    std::cout<<"What is your name?:";
    std::cin>>mName;
    std::cout<<"How many do you have money?:";
    std::cin>>mStack;
    std::cout<<std::endl;
    
}
int32 Player::Bet(Action action,int32 & raisestack)
{
    int32 Return_Stack=0;
    if(action==Fold)
    {
        mAction=Fold;
        std::cout<<"Fold!!"<<std::endl;
    }
    else if(action==Call)
    {
        mAction=Call;
        if(mStack<raisestack)
        {
            
            Return_Stack=mStack;
            mStack=0;
            mAction=Allin;
            std::cout<<"All-In!!"<<std::endl;
            return Return_Stack;
        }
        mStack-=raisestack;
        Return_Stack=raisestack;
    }
    else if(action==Raise)
    {
        mAction=Raise;
        std::cout<<"How much bet?:";
        while(std::cin>>Return_Stack)
        {
            if(Return_Stack>mStack)
            {
                std::cout<<"You don't have this Stack!! again bet"<<std::endl;
                std::cout<<"How much bet?:";
                continue;
            }
            else if(Return_Stack<raisestack)
            {
                std::cout<<"You must bet more than "<<raisestack<<std::endl;
                std::cout<<"How much bet?:";
                continue;
            }
            else if(Return_Stack<=mStack)
            {
                std::cout<<"Raise Money:"<<Return_Stack<<std::endl;
                mStack-=Return_Stack;
                raisestack+=(Return_Stack-raisestack);
                break;
            }
        }
    }
    else if(action==Allin)
    {
        mAction=Allin;
        Return_Stack=mStack;
        Return_Stack>raisestack ? raisestack+=(Return_Stack-raisestack) : raisestack;
        mStack=0;
        std::cout<<"All-In!!!"<<std::endl;
    }
    return Return_Stack;
}


void Player::PlayerHandInfo()
{
    mHand.HandInfo();
    std::string rank;
    switch (mRank)
    {
        case StraihtFlush:rank="Straight Flush";break;
        case FourKind:rank="Four-kind";break;
        case FullHouse:rank="Full House";break;
        case Flush:rank="Flush";break;
        case Straight:rank="Straight";break;
        case ThreeKind:rank="Threeple";break;
        case twoPair:rank="Two Pair";break;
        case onePair:rank="One Pair";break;
        default:rank="No Pair";break;
    }
    std::cout<<"Your Hand <"<<rank<<"> 입니다."<<std::endl;
}
Player& Player::operator=(const Hand & ihand)
{
    this->mHand=ihand;
    this->mRank=mHand.Check_Rank();
    return *this;
}
Player& Player::operator=(const Card &icard)
{
    this->mHand=icard;
    this->mRank=mHand.Check_Rank();
    return *this;
}
Player& Player::operator=(Host &ihost)
{
    this->mHand=ihost.GiveCard();
    this->mRank=this->Rank();
    return *this;
}
PokerRank Player::Rank()
{
    return mHand.Check_Rank();
}
Match Player::operator==(Player & p1)
{
        if(this->mRank>p1.mRank)
            return Win;
        else if(this->mRank==p1.mRank)
        {
            Hand h1,h2;
            h1=this->GetHand();
            h2=p1.GetHand();
            Match a=compare(h1, h2);
            return a;
        }
        else
            return Defeat;
}
bool Player::operator<(const Player & p1)
{
    return this->mRank>p1.mRank;
}
void Player::PlayerFullInfo()
{
    this->PlayerHandInfo();
    std::cout<<"Your Stack:"<<this->GetStack()<<std::endl;
}
