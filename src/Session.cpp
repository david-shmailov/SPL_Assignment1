//
// Created by David on 31/10/2020.
//
#include <iostream>
#include <fstream>

#include "../include/Session.h"


using json = nlohmann::json;

////////Sessoin////////////
Session::Session(const std::string& path):g(Graph()),treeType(),agents(),infected(queue()),cycle(0),non_virus_free() {  // constructor
    std::ifstream i(path);// check this problem
    json j;
    j=json ::parse(i);
    std::vector<std::vector<int>> matrix =j["graph"];

    setGraph(Graph(matrix));
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

Session::Session(const Session &other):g(other.g),treeType(other.treeType),agents(),
                                       infected(other.infected),cycle(other.cycle),non_virus_free(){// copy constructor
    for (auto * otherAgent : other.agents ){
        Agent *n = otherAgent->clone();
        agents.push_back(n);}
    for (auto * otherAgent : other.non_virus_free ){
        Agent *n = otherAgent->clone();
        non_virus_free.push_back(n);
    }
}

Session::~Session(){// destructor
    for (auto * delAgent : this->agents ){
        if(delAgent)
            delete delAgent;
    }
    agents.clear();
    for (auto * delAgent : this->non_virus_free ){
        if(delAgent)
            delete delAgent;
    }
    non_virus_free.clear();
}
Session::Session(Session &&other):g(other.g),treeType(other.treeType),agents(other.agents),
                                  infected(other.infected),cycle(other.cycle),non_virus_free(other.non_virus_free){// move constructor
    other.agents.clear();
    other.non_virus_free.clear();
}



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

        for (auto inAgent : non_virus_free) {
            agents.push_back(inAgent); //append the non_virus_free with agent
        }
        non_virus_free.clear(); // clear this cycle non_virus_free
        for (auto curAgent : agents)
            curAgent->act(*this);
        cycle++;
    }
    Session::makefile();
}



void Session::makefile() {// output function
    json j;
    j["graph"]=g.getMatrix();
    std::vector<int> v;
    int size=g.getMatrix().size();
    for(int i=0;i<size;i++){
        if(g.isInfected(i)) v.push_back(i);
    }
    j["infected"]=v;
    std::ofstream i("output.json");
    i<<j;
}

void Session::enqueueInfected(int i) {infected.enqueue(i);}
int Session::dequeueInfected() {
    int i= infected.peek();
    infected.dequeue();
    return i;}
bool Session::isEmptyQueue() {return infected.isEmpty();}

std::vector<Agent *> Session::getAgent() const{ return  agents;}
void Session::addAgent(const Agent &agent) {// remember to delete this agent after call this function
    Agent* clone = agent.clone();
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
    int size=i.size()-1;
    for (int j=0;j<size;j++)
        i[j]=i[j+1];
    i.pop_back();
}




