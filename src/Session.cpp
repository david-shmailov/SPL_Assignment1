//
// Created by David on 31/10/2020.
//
#include <iostream>
#include <fstream>

#include "../headers/Session.h"


using json = nlohmann::json;

////////Sessoin////////////
Session::Session(const std::string& path):g(Graph()) {  // constructor
    std::ifstream i(path);// check this problem
    json j;
    j << i;

    std::vector<std::vector<int>> matrix =j["graph"];

    g = Graph(matrix);
    cycle=0;
    if(j["tree"]=="M") treeType=MaxRank; // initial treeType
    else if(j["tree"]=="R") treeType=Root;
    else if(j["tree"]=="C") treeType=Cycle;
    for (auto elem: j["agents"]){
        if(elem[0]=="V") {
            g.set_isNonVirusFree(elem[1]);
            Virus *v=new Virus(elem[1]);// initial virus
            non_virus_free.push_back(v);
        }
        else if(elem[0]=="C") {

            ContactTracer *t = new ContactTracer();
            non_virus_free.push_back(t);
        }
    }
     infected=queue();


}

Session::Session(const Session &other) {// copy constructor
    g = other.g;
    treeType=other.treeType;
    cycle=other.cycle;
    infected=other.infected;
    for (auto * otherAgent : other.agents ){
        Agent *n = otherAgent->clone();
        agents.push_back(n);
    }
    for (auto * otherAgent : other.non_virus_free ){
        Agent *n = otherAgent->clone();
        non_virus_free.push_back(n);
    }
    infected=queue();
}

Session::~Session(){// destructor
    for (auto * addAgent : this->agents ){
        if(addAgent)
            delete addAgent;
    }
    agents.clear();
}
Session::Session(Session &&other):g(other.g),treeType(other.treeType),cycle(other.cycle),
     infected(other.infected),agents(other.agents),non_virus_free(other.non_virus_free){}// move constructor



const Session & Session::operator=(const Session &other) {// assignment operator
    g = other.g;
    treeType=other.treeType;
    cycle=other.cycle;
    infected=other.infected;
    for (auto * oldAgent : this->agents ){//delete the old agents
        if(oldAgent)
            delete oldAgent;
    }
    agents.clear();
    for (auto * otherAgent : other.agents ){// add other's agents
        agents.push_back(otherAgent);
    }
    for (auto * oldAgent : this->non_virus_free ){//delete the old agents
        if(oldAgent)
            delete oldAgent;
    }
    non_virus_free.clear();
    for (auto * otherAgent : other.non_virus_free ) {// add other's agents
        non_virus_free.push_back(otherAgent);
    }

    return *this;

}
const Session & Session::operator=(Session &&other) {// move assignment operator
    std::swap(other.agents,this->agents);
    std::swap(other.non_virus_free,this->non_virus_free);
    g=other.g;
    treeType=other.treeType;
    cycle=other.cycle;
    infected=other.infected;

    return *this;
}


void Session::simulate() {
    while (!non_virus_free.empty()) {
        cycle++;
        for (auto inAgent : non_virus_free) {
            agents.push_back(inAgent); //append the non_virus_free with agent
        }
        non_virus_free.clear(); // clear this cycle non_virus_free
        for (auto curAgent : agents)
            curAgent->act(*this);
    }
    Session::makefile();
 }



void Session::makefile() {// output function
    json j;
    j["Graph"]=g.getMatrix();
    std::vector<int> v;
    for(auto vl: v) v.push_back(vl);
    j["infected"]=v;
    std::ofstream i("output.json");
    j>>i;
}

void Session::enqueueInfected(int i) {infected.enqueue(i);}
int Session::dequeueInfected() {
    int i= infected.peek();
    infected.dequeue();
    return i;}
bool Session::isEmptyQueue() {infected.isEmpty();}

std::vector<Agent *> Session::getAgent() const{ return  agents;}
void Session::addAgent(const Agent &agent) {
    Agent* clone = agent.clone();//TODO remember to delete this agent somewhere.
    agents.push_back(clone);
}

TreeType Session::getTreeType() const {return treeType;}

void Session::setGraph(const Graph &graph) {g=graph;}
Graph Session::getGraphConst() const  {return g;}
Graph & Session::getGraph() {return g;}

void Session::addNon_virus_free(Agent *nonVirusFree) {non_virus_free.push_back(nonVirusFree);}///change it to const

int Session::getCycle() const {return cycle;}


/////////// queue////////////
queue::queue() :i(0){};//constructor
queue::queue(const queue &g) :i(g.i){};// copy constructor
queue::queue(queue &&other):i(other.i) {};// move constructor
const queue & queue::operator=(queue &&other) {i=other.i; return *this;}// assignment operator
const queue & queue::operator=(const queue &other) {i=other.i; return  *this;}// move assignment operator
bool queue::isEmpty() {return i.empty();};
void queue::enqueue(int n){i.push_back(n);};
int queue::peek() {return i[0];}
void queue::dequeue() {
    for (int j=0;j<i.size()-1;j++)
        i[j]=i[j+1];
    i.pop_back();
}




