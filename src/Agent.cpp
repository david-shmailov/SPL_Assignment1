//
// Created by David on 31/10/2020.
//

#include "../headers/Agent.h"
///////////////Agent//////////////
Agent::Agent() {};// constructor
Agent::Agent(const Agent &copy){};// copy constructor
Agent::Agent(Agent &&other){};// move constructor
const Agent & Agent::operator=(Agent &&other) {//  move assignment operator
    return *this;
};
const Agent & Agent::operator=(const Agent &other) {//assignment operator
    return *this;}

//void Agent::act() {};// TODO

//////////////////Virus/////////////////
Virus::Virus(int nodeInd,Session& session): nodeInd(nodeInd), Agent(){};// constructor
Virus::Virus(const Virus &v): Agent(v) ,nodeInd(v.nodeInd) {};// copy constructor
Virus::Virus(Virus &&other):Agent(other),nodeInd(other.nodeInd) {}// move constructor

Agent* Virus::clone() const{
    Virus* clone = new Virus(*this);
    return clone;
}

//void Virus::act() {};//TODO


////////////ContactTracer////////////////
ContactTracer::ContactTracer(Session& session):Agent {};// constructor
ContactTracer::ContactTracer(const ContactTracer &a): Agent(a) {};// copy constructor
ContactTracer::ContactTracer(ContactTracer &&other):ContactTracer(other){}// move constructor

Agent* ContactTracer::clone() const {
    ContactTracer* clone = new ContactTracer(*this);
    return clone;
}

//void ContactTracer::act() {};//TODO