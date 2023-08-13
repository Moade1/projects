#include "../include/SelectionPolicy.h"
#include <iostream>

using std::cout;
using std::endl;
SelectionPolicy::SelectionPolicy(){}
SelectionPolicy::~SelectionPolicy(){}

void MandatesSelectionPolicy::select(Simulation &s,Agent &a,vector<int> &PartiesThatMeetsTheConditiony){
    if(PartiesThatMeetsTheConditiony.size()==0)
        return;
    int maxMandates=0;
    int maxParty=0;
    for(unsigned int i=0;i<PartiesThatMeetsTheConditiony.size();i++){
        int currMandates=s.getGraph().getParty(PartiesThatMeetsTheConditiony[i]).getMandates();
        if(currMandates>maxMandates){
            maxMandates=currMandates;
            maxParty=PartiesThatMeetsTheConditiony[i];
        }
    }
    
    
    s.addOffer(maxParty,a);
}

SelectionPolicy* MandatesSelectionPolicy::clone(){
    return new MandatesSelectionPolicy();
}
MandatesSelectionPolicy::MandatesSelectionPolicy(){};
MandatesSelectionPolicy::~MandatesSelectionPolicy(){};


void EdgeWeightSelectionPolicy::select(Simulation &s,Agent &a,vector<int> &PartiesThatMeetsTheConditiony){
   if(PartiesThatMeetsTheConditiony.size()==0)
        return;
    int maxEdge=0;
    int maxParty=0;

    for(unsigned int i=0;i<PartiesThatMeetsTheConditiony.size();i++){
        int currEdge=s.getGraph().getEdgeWeight(a.getPartyId(),PartiesThatMeetsTheConditiony[i]);
        if(currEdge>maxEdge){
            maxEdge=currEdge;
            maxParty=PartiesThatMeetsTheConditiony[i];
        }
    } 
    
    s.addOffer(maxParty,a);
}
SelectionPolicy* EdgeWeightSelectionPolicy::clone(){
    return new EdgeWeightSelectionPolicy();
}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){};
EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){};

