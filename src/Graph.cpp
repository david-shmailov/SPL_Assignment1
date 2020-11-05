//
// Created by David on 31/10/2020.
//

#include "../headers/Graph.h"
#include <vector>
// TODO test this
Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix) //constructor
                                       , infected(std::vector<bool> (edges.size(),false)) {}

Graph::Graph(const Graph &g) : edges(g.edges),infected(g.infected){};//copy constructor
Graph::Graph(Graph &&other):edges(other.edges),infected(other.infected) {}//move constructor
const Graph & Graph::operator=(const Graph &other) { // assignment operator
    edges=other.edges;
    infected=other.infected;
    return *this;
}
const Graph & Graph::operator=(Graph &&other) {// move assignment operator
    edges=other.edges;
    infected=other.infected;
    return *this;
}


bool Graph::isInfected(int nodeInd) {
    return infected[nodeInd];
}

std::vector<std::vector<int>> const Graph::getMatrix() {return edges;}

void Graph::infectNode(int nodeInd) {
    this->infected[nodeInd] = true;
}

void Graph::isolateNode(int nodeInd) {
    for (int i = 0; i<edges.size();i++){
        this->edges[nodeInd][i]=0;
        this->edges[i][nodeInd]=0;
    }
}





