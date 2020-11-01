//
// Created by David on 31/10/2020.
//

#include "../headers/Session.h"

std::vector<Agent *> Session::getAgent() const{ return  agents;}
void Session::addAgent(const Agent &agent) {}
void Session::setGraph(const Graph &graph) {
    this-> g = graph;
}

