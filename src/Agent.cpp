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



//////////////////Virus/////////////////
Virus::Virus(int nodeInd): nodeInd(nodeInd), Agent(){};// constructor
Virus::Virus(const Virus &v): Agent(v) ,nodeInd(v.nodeInd) {};// copy constructor
Virus::Virus(Virus &&other):Agent(other),nodeInd(other.nodeInd) {}// move constructor
Agent* Virus::clone() const{
    Virus* clone = new Virus(*this);
    return clone;
}

void Virus::act(Session& session) {
    if(!session.getGraph().isInfected(nodeInd)){ // non_virus_free turn to infected
        session.getGraph().infectNode(nodeInd);//turn infected
        session.enqueueInfected(nodeInd);//in to queue infected
        session.getGraph().reset_isNonVirusFree(nodeInd);// no longer non_virus_free
    }
    for(int i =0; i<session.getGraph().getMatrix()[nodeInd].size();i++) {
        if (session.getGraph().getMatrix()[nodeInd][i] == 1 // check if this node is neighbor
            && !session.getGraph().isNonVirusFree(i) //check if not NonVirusFree
            && !session.getGraph().isInfected(i)) { //check if this node is not infected
            Virus *v= new Virus(i); // create new virus
            session.addNon_virus_free(v); // add it to Non_virus_free
            session.getGraph().set_isNonVirusFree(i);// is non_virus_free
            break;
        }
    }
};


////////////ContactTracer////////////////
ContactTracer::ContactTracer():Agent() {};// constructor
ContactTracer::ContactTracer(const ContactTracer &a): Agent(a) {};// copy constructor
ContactTracer::ContactTracer(ContactTracer &&other):ContactTracer(other){}// move constructor
Agent* ContactTracer::clone() const {
    ContactTracer* clone = new ContactTracer(*this);
    return clone;
}
void ContactTracer::act(Session& session) {
    if(!session.isEmptyQueue()) {
        Tree *curTree = Tree::BFS(session, session.dequeueInfected());
        int nodeIso = (*curTree).traceTree();
        session.getGraph().isolateNode(nodeIso);
        delete curTree;
    }
};