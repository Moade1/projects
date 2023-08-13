#pragma once
#include "Graph.h"
#include <vector>
#include "Simulation.h"





using std::vector;
class SelectionPolicy {
    public:
    SelectionPolicy();
    virtual~SelectionPolicy();
    virtual void select(Simulation &s,Agent &a,vector<int> &PartiesThatMeetsTheConditiony)=0;
   
    virtual SelectionPolicy* clone()=0;
};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
     MandatesSelectionPolicy();
    ~MandatesSelectionPolicy() override;
    void select(Simulation &s,Agent &a,vector<int> &PartiesThatMeetsTheConditiony)override;
   
    SelectionPolicy* clone()override;
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
    EdgeWeightSelectionPolicy();
    ~EdgeWeightSelectionPolicy() override;
    void select(Simulation &s,Agent &a,vector<int> &PartiesThatMeetsTheConditiony)override;

     SelectionPolicy* clone()override;
};

