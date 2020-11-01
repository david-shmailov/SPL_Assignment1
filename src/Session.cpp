//
// Created by David on 31/10/2020.
//

#include "../headers/Session.h"
void Session::Session(const std::string &path) {}
std::vector<Agent *> Session::getAgent() const{ return  agents;}
void Session::addAgent(const Agent &agent) {agents.push_back(agent);}
void Session::setGraph(const Graph &graph) {g=graph;}

