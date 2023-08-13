#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
   //rule of 5
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    virtual ~Agent();
    Agent();
    Agent(const Agent &old_Agent);
    Agent (Agent &&other_Agent);
    Agent& operator=(const Agent &other_Agent);
    Agent& operator=(Agent &&other_Agent);

 //finsh rule of 5   
    int getPartyId() const;
    int getId() const;
    void step(Simulation &sim);

    //my fun:
    void setcoalitionId(int cocoalitionID);
    int getcoalitionId() const;
    SelectionPolicy* getSelectionPolicy()const;
    void setId(int AgentId);
    void setPartyId(int partId);
private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int coalitionId;
};
