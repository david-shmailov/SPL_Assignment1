//
// Created by David on 31/10/2020.
//

#include "../headers/Agent.h"
Agent::Agent(Session& session): session(session) {};
void Agent::act() {};// TODO
Virus::Virus(int nodeInd,Session& session): nodeInd(nodeInd), Agent(session){};
void Virus::act() {};//TODO
ContactTracer::ContactTracer(Session& session):Agent(session) {};
void ContactTracer::act() {};//TODO