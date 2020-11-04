//
// Created by David on 31/10/2020.
//
#include <iostream>
#include <fstream>
#include "json.hpp"
#include "../headers/Session.h"
#include "../headers/Graph.h"

using json = nlohmann::json;

Session::Session(const std::string &path) {  // constructor
    std::ifstream i("config1.json");// check this problem
        json j;
        j << i;

    std::vector<std::vector<int>> matrix =j["graph"];
    g= Graph(matrix); // initial graph
    if(j["tree"]=='M') treeType=MaxRank; // initial treeType
    else if(j["tree"]=='R') treeType=Root;
    else if(j["tree"]=='C') treeType=Cycle;
    for (auto elem: j["agents"]){

        if(elem[0]=="V") {
            enqueueInfected(elem[1]);// add the node initial to infected
            Virus v( , elem[1] );/// TODO need to initial virus
            }
        if(elem[0]=="C") ContactTracer t();///TODO  need to initial contactTracer

        }

}

Session::Session(const Session &other) {
    g = Graph(other.getGraph());
    treeType=other.treeType;
    for (int i=0; i<other.agents.size();i++){
        Agent n= Agent(other.agents[i]);
        agents.push_back(Agent(other.agents[i]));
    }

} // copy constructor


void Session::simulate() {}// TODO
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




