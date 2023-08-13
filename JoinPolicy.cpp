#include "../include/JoinPolicy.h"
#include "../include/Agent.h"
#include "../include/Simulation.h"
JoinPolicy::JoinPolicy(){}
JoinPolicy::~JoinPolicy(){}
#include<iostream>

using namespace std;
using std::cout;
using std::endl;


void MandatesJoinPolicy::join(Simulation &s,Party &p){

    int maxMandates=0;
    int maxCoalition=0;
    Agent maxAgent;
    for(Agent a:p.getoffers()){
        if(s.getNumOfMandatesInCoalitions(a.getcoalitionId())>maxMandates){
            maxMandates=s.getNumOfMandatesInCoalitions(a.getcoalitionId());
            maxCoalition=a.getcoalitionId();
            maxAgent = a;
        }
    }
    s.addParty(p.getId(),maxCoalition);
     
    maxAgent.setcoalitionId(maxCoalition);
    maxAgent.setPartyId(p.getId());
    maxAgent.setId(s.getAgents().size());
    s.addAgent(maxAgent);
};
   

JoinPolicy* MandatesJoinPolicy::clone(){
    return new MandatesJoinPolicy();
} 

MandatesJoinPolicy::MandatesJoinPolicy(){}
MandatesJoinPolicy::~MandatesJoinPolicy(){}



void LastOfferJoinPolicy::join(Simulation &s,Party &p){
    
    Agent a = p.getoffers()[p.getoffers().size()-1];
    s.addParty(p.getId(),a.getcoalitionId());
    Agent moade(a);
    moade.setcoalitionId(a.getcoalitionId());
    moade.setPartyId(p.getId());
    moade.setId(s.getAgents().size());
    s.addAgent(moade);   
}

JoinPolicy* LastOfferJoinPolicy::clone(){
    return new LastOfferJoinPolicy();
}
LastOfferJoinPolicy::LastOfferJoinPolicy(){};
LastOfferJoinPolicy::~LastOfferJoinPolicy(){};