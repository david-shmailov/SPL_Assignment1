//
// Created by David on 31/10/2020.
//

#include "../headers/Agent.h"
Agent::Agent(Session& session): session(session) {};
Agent::Agent(const Agent &copy):session(copy.session) {};
Agent::Agent(Agent &&other):session(other.session ) {};
const Agent & Agent::operator=(Agent &&other) {
    session=other.session;
    return *this;
};
const Agent & Agent::operator=(const Agent &other) {
    session=other.session;
    return *this;
}



//void Agent::act() {};// TODO
Virus::Virus(int nodeInd,Session& session): nodeInd(nodeInd), Agent(session){};
Virus::Virus(const Virus &v): Agent(v) ,nodeInd(v.nodeInd) {};
//void Virus::act() {};//TODO
ContactTracer::ContactTracer(Session& session):Agent(session) {};
ContactTracer::ContactTracer(const ContactTracer &a): Agent(a) {};
//void ContactTracer::act() {};//TODO