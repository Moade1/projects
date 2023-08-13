#include "Graph.h"
#include "Agent.h"
#include<iostream>
using std::cout;
using std::endl;
Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges),timers(vector<int>())
{
    // You can change the implementation of the constructor, but not the signature!
    for(unsigned int i=0;i<mVertices.size();i++)
        timers.push_back(0);
}
int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

//my fun::
void Graph::setparties(Simulation &sim){
    for (Party p:mVertices)
    {
        p.step(sim);
    }
    

}
vector<Party> Graph::getmVertices()const{
    return mVertices;
}
int Graph::getTime(int IdParty)const{
    return timers[IdParty];
}
void Graph::joinParty(int PartyId){
    mVertices[PartyId].setState(Joined);
}
 vector<int> Graph::getPartiesThatMeetsTheConditiony(Agent &a)const
{
    vector<int> ruselt;
    for(int i=0;i<getNumVertices();i++){
        if(!getParty(i).gotOfferFromCoalition(a.getcoalitionId())){
        if(getEdgeWeight(i,a.getPartyId())>0){
        if(getParty(i).getState()!=Joined){
            ruselt.push_back(getParty(i).getId());
        }
        }
        }
    
    }



    return ruselt;
}

void Graph::Tick(int PartId){
    timers[PartId]++;
}
void Graph::addOffer(int PartId,Agent &a){
    mVertices[PartId].addOffer(a);
    
    if(mVertices[PartId].getState()==Waiting)
        mVertices[PartId].setState(CollectingOffers);
}