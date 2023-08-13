#include "Party.h"
#include "JoinPolicy.h"
#include "Agent.h"
#include "Simulation.h"
#include<iostream>


using std::cout;
using std::endl;
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),offeringAgents(vector<Agent>())
{
    // You can change the implementation of the constructor, but not the signature!
    //offeringAgents = vector<Agent*>();
}

//destructor
Party::~Party(){
    if (mJoinPolicy)
    {
        delete mJoinPolicy;
    }
    
}
//copy constructer
Party::Party(const Party &otherParty):mId(otherParty.mId), mName(otherParty.mName),mMandates(otherParty.mMandates),mJoinPolicy(otherParty.mJoinPolicy->clone()),mState(otherParty.mState),offeringAgents(otherParty.offeringAgents){

}
//move constructer

Party::Party(Party &&otherParty):mId(otherParty.mId), mName(otherParty.mName),mMandates(otherParty.mMandates),mJoinPolicy(otherParty.mJoinPolicy),mState(otherParty.mState),offeringAgents(otherParty.offeringAgents){
    otherParty.mJoinPolicy=nullptr;
}
///copy assignment operator
Party& Party:: operator=(const Party &otherParty){
    if(this!=&otherParty){
    mId=otherParty.mId;
    mName=otherParty.mName;
    mMandates=otherParty.mMandates;
    mState=otherParty.mState;
    if (mJoinPolicy)
    {
        delete mJoinPolicy;
    }
        mJoinPolicy=otherParty.mJoinPolicy->clone();
    }
     return *this;   
    
}

///move assignment operator
Party& Party:: operator=(Party &&otherParty){
    if(this!=&otherParty){
    mId=otherParty.mId;
    mName=otherParty.mName;
    mMandates=otherParty.mMandates;
    mState=otherParty.mState;
    if (mJoinPolicy)
        delete mJoinPolicy;
    mJoinPolicy=otherParty.mJoinPolicy;
    otherParty.mJoinPolicy=nullptr;
    }
    return *this;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    // TODO: implement this method
    if(mState==State::CollectingOffers){
        s.Tick(mId);
         if(s.getGraph().getTime(mId)==3){
            s.joinParty(mId);
            mJoinPolicy->join(s,*this);
        }
    }
}

// my fun::
 vector<Agent>& Party::getoffers(){
    return offeringAgents;
}
const int Party::getId()const{
    return mId;
}
bool Party::gotOfferFromCoalition(int coalition1Id)const{
    for(Agent a : offeringAgents){
        if(a.getcoalitionId()==coalition1Id)
            return true;
    }
    return false;
}
void Party::addOffer(Agent &a){
    
    offeringAgents.push_back(a);
   

}
