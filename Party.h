#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;
class Simulation;
class Agent;
class JoinPolicy;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *jp);
    
    virtual ~Party();
    Party(const Party &otherParty);
    Party(Party &&otherParty);
    Party& operator=(const Party &otherParty);
    Party& operator=(Party &&otherPartry);


    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    
    ///my fun::
     vector<Agent>& getoffers();
    const int getId()const;
    bool gotOfferFromCoalition(int coalitionId)const;
    void addOffer(Agent &a);
    
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<Agent> offeringAgents;

};



