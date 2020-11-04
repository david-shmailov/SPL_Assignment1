//
// Created by David on 31/10/2020.
//

#include "../headers/Agent.h"
///////////////Agent//////////////
Agent::Agent(Session& session): session(session) {};// constructor
Agent::Agent(const Agent &copy):session(copy.session) {};// copy constructor
Agent::Agent(Agent &&other):session(other.session ) {};// move constructor
const Agent & Agent::operator=(Agent &&other) {//  move assignment operator
    session=other.session;
    return *this;
};
const Agent & Agent::operator=(const Agent &other) {//assignment operator
    session=other.session;
    return *this;
}
const Session & Agent::getSession() {return session;}
void Agent::setSession(const Agent& other) {this->session=other.session;};
//void Agent::act() {};// TODO

//////////////////Virus/////////////////
Virus::Virus(int nodeInd,Session& session): nodeInd(nodeInd), Agent(session){};// constructor
Virus::Virus(const Virus &v): Agent(v) ,nodeInd(v.nodeInd) {};// copy constructor
Virus::Virus(Virus &&other):Agent(other),nodeInd(other.nodeInd) {}// move constructor
const Virus & Virus::operator=(const Virus &other) {// assignment operator
    nodeInd=other.nodeInd;///problem!!!cant copy const
    setSession(other.getSession());////problem
}
const Virus & Virus::operator=(Virus &&other) {//  move assignment operator
    nodeInd=other.nodeInd;///problem!!! cant copy const

}

//void Virus::act() {};//TODO


////////////ContactTracer////////////////
ContactTracer::ContactTracer(Session& session):Agent(session) {};// constructor
ContactTracer::ContactTracer(const ContactTracer &a): Agent(a) {};// copy constructor
ContactTracer::ContactTracer(ContactTracer &&other):ContactTracer(other){}// move constructor
const ContactTracer & ContactTracer::operator=(const ContactTracer &other) {// assignment operator


}
const ContactTracer & ContactTracer::operator=(ContactTracer &&other) {//  move assignment operator

}
//void Virus::act() {};//TODO
//void ContactTracer::act() {};//TODO