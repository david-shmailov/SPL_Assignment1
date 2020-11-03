//
// Created by David on 31/10/2020.
//

#include "../headers/Session.h"
using json = nlohmann::json;

Session::Session(const std::string &path) {
    std::ifstream i("config1.json");// check this problem
        json j;
        j << i;
        g= Graph(j["graph"]);
        if(j["tree"]=='M') treeType=MaxRank;
        else if(j["tree"]=='R') treeType=Root;
        else if(j["tree"]=='C') treeType=Cycle;
        std::vector<std::vector < std::string , int>> a = j["Agents"];// trying to initial agents
       // for (int j=0; j<a.size();j++ )

                                                                  //need to initial infected
}  //TODO

Session::Session(const Session &session): g(session.g), treeType(session.treeType),
                                       infected(session.infected),agents(session.agents) {}


//void Session::simulate() {}// TODO
void Session::enqueueInfected(int i) {infected.enqueue(i);}
int Session::dequeueInfected() {
    int i= infected.peek();
    infected.dequeue();
    return i;}
std::vector<Agent *> Session::getAgent() const{ return  agents;}
TreeType Session::getTreeType() const {return treeType;}
void Session::addAgent(const Agent &agent) {
    Agent a = agent;
    agents.push_back(&a);}
void Session::setGraph(const Graph &graph) {g=graph;}

Graph Session::getGraph() const {return g;}


int Session::getCycle() const {return cycle;}

queue::queue() {i=new std::vector<int>;};
bool queue::isEmpty() {i->empty();};
void queue::enqueue(int n){i->push_back(n);};
int queue::peek() {(*i)[0];}
int queue::dequeue() {
    for (int j=0;j<i->size()-1;j++)
        (*i)[j]=(*i)[j+1];
    i->pop_back();

}




