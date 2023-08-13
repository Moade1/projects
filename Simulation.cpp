#include "Simulation.h"
#include<iostream>
using std::cout;
using std::endl;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), NumOfMandatesInCoalitions(vector<int>()),coalitions(vector<vector<int>>()){
    // You can change the implementation of the constructor, but not the signature!
  
    for(unsigned int i=0;i<mAgents.size();i++){
        mAgents[i].setcoalitionId(i);
    }
    for (unsigned int i = 0; i < mAgents.size(); i++)
    {
        vector<int> temp;
        
        temp.push_back(mAgents[i].getPartyId());
        coalitions.push_back(temp);
        NumOfMandatesInCoalitions.push_back(mGraph.getParty(mAgents[i].getPartyId()).getMandates());
    }
    
}

void Simulation::step()
{
    
     for(Party p:mGraph.getmVertices()){
       p.step(*this);
    }
    
    for(Agent a:mAgents)
        a.step(*this);//step for all the agent 

}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
       

     bool allJoined = true;

    for(int i=0; i<mGraph.getNumVertices(); i++)
        allJoined = allJoined && mGraph.getParty(i).getState() == Joined;
        
    for(int mandates: NumOfMandatesInCoalitions)
        if(mandates >= 61)
            return true;

    return allJoined;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
//my fun::
void Simulation::joinParty(int PartyId){
    mGraph.joinParty(PartyId);
}
const int Simulation::getNumOfMandatesInCoalitions(int coalitionId)const
{
    return NumOfMandatesInCoalitions[coalitionId];
}
void Simulation::addParty(int partyId,int coalitionId){
    coalitions[coalitionId].push_back(partyId);
    NumOfMandatesInCoalitions[coalitionId]+=mGraph.getParty(partyId).getMandates();
}
void Simulation::Tick(int PartId){
    mGraph.Tick(PartId);
}
void Simulation::addAgent(Agent &a){
    mAgents.push_back(a);
    
}

void Simulation::addOffer(int PartId,Agent &a){
    mGraph.addOffer(PartId,a);
}
//end my fun;;

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return coalitions;
}   
