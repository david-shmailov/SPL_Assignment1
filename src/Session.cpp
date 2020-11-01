//
// Created by David on 31/10/2020.
//

#include "../headers/Session.h"
//void Session::Session(const std::string &path) {}//TODO
//void Session::simulate() {}// TODO
void Session::enqueueInfected(int i) {infected.enqueue(i);}
int Session::dequeueInfected() {
    int i= infected.peek();
    infected.dequeue();
    return i;}
std::vector<Agent *> Session::getAgent() const{ return  agents;}
TreeType Session::getTreeType() {return treeType;}
void Session::addAgent(const Agent &agent) {agents.push_back(agent);}//Problem
void Session::setGraph(const Graph &graph) {g=graph;}



queue::queue() {i=new std::vector<int>;};
bool queue::isEmpty() {i->empty();};
void queue::enqueue(int n){i->push_back(n);};
int queue::peek() {(*i)[0];}
int queue::dequeue() {
    for (int j=0;j<i->size()-1;j++)
        (*i)[j]=(*i)[j+1];
    i->pop_back();

}




