//
// Created by David on 31/10/2020.
//

#include "../headers/Agent.h"
#include "../headers/Tree.h"
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
Virus::Virus(int nodeInd,Session& session): nodeInd(nodeInd), Agent(){};// constructor
Virus::Virus(const Virus &v): Agent(v) ,nodeInd(v.nodeInd) {};// copy constructor
Virus::Virus(Virus &&other):Agent(other),nodeInd(other.nodeInd) {}// move constructor


void Virus::act(Session& session) {
    if(!session.getGraph().isInfected(nodeInd)){ // non_virus_free turn to infected
        session.getGraph().infectNode(nodeInd);//turn infected
        session.enqueueInfected(nodeInd);//in to queue infected
        session.getGraph().set_isNonVirusFree(nodeInd);// no longer non_virus_free
    }
    for(int i =0; i<session.getGraph().getMatrix()[nodeInd].size();i++) {
        if (session.getGraph().getMatrix()[nodeInd][i] == 1 // check if this node is neighbor
            && !session.getGraph().isNonVirusFree(i) //check if not NonVirusFree
            && !session.getGraph().isInfected(i)) { //check if this node is not infected
            Virus *v= new Virus(i,session); // create new virus
            session.addNon_virus_free(v); // add it to Non_virus_free
            break;
        }
    }
};


////////////ContactTracer////////////////
ContactTracer::ContactTracer(Session& session):Agent() {};// constructor
ContactTracer::ContactTracer(const ContactTracer &a): Agent(a) {};// copy constructor
ContactTracer::ContactTracer(ContactTracer &&other):ContactTracer(other){}// move constructor

void ContactTracer::act(Session& session) {
    Tree *curTree=Tree::BFS(session,session.dequeueInfected());
    int nodeIso = (*curTree).traceTree();
    session.getGraph().isolateNode(nodeIso);
    delete curTree;
};