#pragma once
#include <vector>
#include "Party.h"

using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    /*
    Graph(const Graph& graph);
    Graph& operator=(const Graph &graph);
    */
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;


    //my fun:
    void setparties(Simulation &sim);
    int getTime(int IdParty)const;
    void joinParty(int PartId);
    vector<int> getPartiesThatMeetsTheConditiony(Agent &a)const;
    void addOffer(int PartId,Agent &a);
    void Tick(int PartId);
    vector<Party> getmVertices()const;
    
private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
    vector<int> timers;


};
