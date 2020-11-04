//
// Created by David on 31/10/2020.
//

#ifndef SESSION_H_
#define SESSION_H_
#include <iostream>
#include <fstream>
#include "../headers/json.hpp"
#include <vector>
#include <string>


class Agent;
class Graph;


class queue {
public:
    queue();
    void enqueue(int n);
    int dequeue();
    int peek();
    bool isEmpty();
private:
    std::vector<int> *i;
};



class Agent;

enum TreeType{
    Cycle,
    MaxRank,
    Root
};

class Session{ // role of 5
public:
    Session(const std::string& path); // constructor
    Session(const Session & other); // copy constructor
    virtual ~Session(); // destructor
    Session(Session&& other); // move constructor
    const Session& operator =(const Session& other);// assignment operator
    const Session& operator=(Session&& other);// move assignment operator

    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    int getCycle()const;
    void enqueueInfected(int i);
    int dequeueInfected();
    TreeType getTreeType() const;
    Graph getGraph() const;

    std::vector<Agent*> getAgent() const;

private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    queue infected;
    int cycle;
};

#endif
