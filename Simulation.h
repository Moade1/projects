#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;
class Agent;
class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    //my fun::

    const vector<vector<int>> getPartiesByCoalitions() const;
    void joinParty(int PartyId);
    const int getNumOfMandatesInCoalitions(int coalitionId) const;
    void addParty(int PartyId,int CoalitionId);
    void addAgent(Agent &a);
    void addOffer(int PartId,Agent &a);
    void Tick(int PartId);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<int> NumOfMandatesInCoalitions;
    vector<vector<int>> coalitions;
};
