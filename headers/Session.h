//
// Created by David on 31/10/2020.
//

#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include "Graph.h"

class Agent;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{
public:
    Session(const std::string& path);

    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);

    void enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType();

private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
};

#endif
