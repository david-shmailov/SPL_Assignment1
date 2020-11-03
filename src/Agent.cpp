//
// Created by David on 31/10/2020.
//

#include "../headers/Agent.h"
Agent::Agent(Session& session): session(session) {};
Agent::Agent(const Agent &a):session(a.session) {};
//void Agent::act() {};// TODO
Virus::Virus(int nodeInd,Session& session): nodeInd(nodeInd), Agent(session){};
Virus::Virus(const Virus &v): Agent(v) ,nodeInd(v.nodeInd) {};
//void Virus::act() {};//TODO
ContactTracer::ContactTracer(Session& session):Agent(session) {};
ContactTracer::ContactTracer(const ContactTracer &a): Agent(a) {};
//void ContactTracer::act() {};//TODO