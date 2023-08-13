#include "Agent.h"
#include "SelectionPolicy.h"
#include <iostream>
using namespace std;
//constructor
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy),coalitionId(0)
{
    // You can change the implementation of the constructor, but not the signature!
}
//destructor
Agent::~Agent(){
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    
}
Agent::Agent(): mAgentId(-1), mPartyId(-1), mSelectionPolicy(nullptr), coalitionId(-1){
}
//copy constructor 
Agent::Agent(const Agent &old_Agent):mAgentId(old_Agent.mAgentId),mPartyId(old_Agent.mPartyId),mSelectionPolicy(old_Agent.mSelectionPolicy->clone()),coalitionId(old_Agent.coalitionId){
}
//move constructor
Agent::Agent(Agent&& other_Agent):mAgentId(other_Agent.mAgentId),mPartyId(other_Agent.mPartyId),mSelectionPolicy(other_Agent.mSelectionPolicy),coalitionId(other_Agent.coalitionId){
    other_Agent.mSelectionPolicy=nullptr;
}
//copy assignment operator
Agent& Agent::operator=(const Agent &other_Agent){
    if(this!=&other_Agent){
    mAgentId=other_Agent.mAgentId;
    mPartyId=other_Agent.mPartyId;
    // if(mSelectionPolicy != nullptr)
    //     delete mSelectionPolicy;
     mSelectionPolicy=other_Agent.mSelectionPolicy->clone();
    coalitionId=other_Agent.coalitionId;
    }
     return *this;
}
//move assignment operator
Agent& Agent::operator=(Agent &&other_Agent){
    if(this!=&other_Agent){
    mAgentId=other_Agent.mAgentId;
    mPartyId=other_Agent.mPartyId;
    coalitionId=other_Agent.coalitionId;
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    mSelectionPolicy=other_Agent.mSelectionPolicy;
    other_Agent.mSelectionPolicy=nullptr;
  
    }
      return *this;
}
int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}
void Agent:: setId(int AgentId){
    mAgentId=AgentId;
}
void Agent::setPartyId(int partyId){
    mPartyId=partyId;
}
void Agent::step(Simulation &sim)
{

    // TODO: implement this method
 
    vector<int> temp=sim.getGraph().getPartiesThatMeetsTheConditiony(*this);
    mSelectionPolicy->select(sim,*this,temp);

}

//myfun::
void Agent::setcoalitionId(int coalitionID){
    coalitionId=coalitionID;
}
int Agent::getcoalitionId()const{
    return coalitionId;
}
SelectionPolicy* Agent::getSelectionPolicy()const{
    return mSelectionPolicy;
}

