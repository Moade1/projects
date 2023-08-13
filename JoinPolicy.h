#pragma once

#include <string>
using std::string;

class Party;
class Simulation;



class JoinPolicy {
    public:
    JoinPolicy();
    JoinPolicy(const JoinPolicy& other);
    virtual ~JoinPolicy();
    virtual void join(Simulation &s,Party &p)=0;
    virtual JoinPolicy* clone()=0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
    MandatesJoinPolicy();
    MandatesJoinPolicy(const MandatesJoinPolicy& other);
    ~MandatesJoinPolicy() override;
    void join(Simulation &s,Party &p) ;
    virtual JoinPolicy* clone();

};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
    LastOfferJoinPolicy();
    LastOfferJoinPolicy(const LastOfferJoinPolicy& other);
    ~LastOfferJoinPolicy() override;
    void join(Simulation &s,Party &p) ;
    JoinPolicy* clone();
};