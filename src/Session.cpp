//
// Created by David on 31/10/2020.
//
#include <iostream>
#include <fstream>
#include "../headers/json.hpp"
#include "../headers/Session.h"
#include "../headers/Graph.h"
#include "../headers/Agent.h"

using json = nlohmann::json;

////////Sessoin////////////
Session::Session(const std::string &path):g(Graph()) {  // constructor
    std::ifstream i("config1.json");// check this problem
        json j;
        j << i;

    std::vector<std::vector<int>> matrix =j["graph"];

    g = Graph(matrix);
    cycle=0;
    if(j["tree"]=='M') treeType=MaxRank; // initial treeType
    else if(j["tree"]=='R') treeType=Root;
    else if(j["tree"]=='C') treeType=Cycle;
    for (auto elem: j["agents"]){

        if(elem[0]=="V") {
            enqueueInfected(elem[1]);// add the node initial to infected
            Virus *v=new Virus(  elem[1],*this );// initial virus
            agents.push_back(v);
            }
        else if(elem[0]=="C") ContactTracer t();//initial contactTracer
           ContactTracer *t=new ContactTracer(*this);
           agents.push_back(t);
        }


}

Session::Session(const Session &other) {// copy constructor
     g = other.g;
    treeType=other.treeType;
    cycle=other.cycle;
    infected=other.infected;
    for (auto * otherAgent : other.agents ){
        Agent *n = new Agent(*otherAgent);
        agents.push_back(n);
    }
}

Session::~Session(){// destructor
    for (auto * addAgent : this->agents ){
        if(addAgent)
        delete addAgent;
    }
    agents.clear();
}

Session::Session(Session &&other):g(other.g),treeType(other.treeType),cycle(other.cycle),
                         infected(other.infected),agents(other.agents){}// move constructor

const Session & Session::operator=(const Session &other) {// assignment operator
    for (auto * oldAgent : this->agents ){//delete the old agents
        if(oldAgent)
            delete oldAgent;
    }
    agents.clear();
    for (auto * otherAgent : other.agents ){// add other's agents
        agents.push_back(otherAgent);
    }
    g = other.g;
    treeType=other.treeType;
    cycle=other.cycle;
    infected=other.infected;
    return *this;

}
const Session & Session::operator=(Session &&other) {// move assignment operator
    std::swap(other.agents,this->agents);
    g=other.g;
    treeType=other.treeType;
    cycle=other.cycle;
    infected=other.infected;
    return *this;
}


void Session::simulate() {}// TODO
void Session::makefile() {// output function
    json j;
    j["Graph"]=g.getMatrix();
    std::vector<int> v;
    for(auto vl: v) v.push_back(vl);
    j["infected"]=v;
}
void Session::enqueueInfected(int i) {infected.enqueue(i);}
int Session::dequeueInfected() {
    int i= infected.peek();
    infected.dequeue();
    return i;}
std::vector<Agent *> Session::getAgent() const{ return  agents;}
TreeType Session::getTreeType() const {return treeType;}

void Session::addAgent(const Agent &agent) {
    Agent* clone = agent.clone();//TODO remember to delete this agent somewhere.
    agents.push_back(clone);
}

void Session::setGraph(const Graph &graph) {g=graph;}

Graph Session::getGraph() const {return g;}


int Session::getCycle() const {return cycle;}

/////////// queue////////////
queue::queue() :i(0){};//constructor
queue::queue(const queue &g) :i(g.i){};// copy constructor
queue::queue(queue &&other):i(other.i) {};// move constructor
const queue & queue::operator=(queue &&other) {i=other.i; return *this;}// assignment operator
const queue & queue::operator=(const queue &other) {i=other.i; return  *this;}// move assignment operator
bool queue::isEmpty() {i.empty();};
void queue::enqueue(int n){i.push_back(n);};
int queue::peek() {i[0];}
int queue::dequeue() {
    for (int j=0;j<i.size()-1;j++)
        i[j]=i[j+1];
    i.pop_back();
}




