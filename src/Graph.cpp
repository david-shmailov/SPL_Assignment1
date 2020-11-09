//
// Created by David on 31/10/2020.
//

#include "../include/Graph.h"
#include <vector>

// TODO test this
Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix) //constructor
        , infected(std::vector<bool> (edges.size(),false))
        ,isNon_virus_free(std::vector<bool> (edges.size(),false)){}
Graph::Graph():edges(),infected(),isNon_virus_free() {};
Graph::Graph(const Graph &g) : edges(g.edges),infected(g.infected),isNon_virus_free(g.isNon_virus_free){} ;//copy constructor
Graph::Graph(Graph &&other):edges(other.edges),infected(other.infected),isNon_virus_free(other.isNon_virus_free) {}//move constructor
const Graph & Graph::operator=(const Graph &other) { // assignment operator
    edges=other.edges;
    infected=other.infected;
    isNon_virus_free=other.isNon_virus_free;
    return *this;
}
const Graph & Graph::operator=(Graph &&other) {// move assignment operator
    edges=other.edges;
    infected=other.infected;
    isNon_virus_free=other.isNon_virus_free;
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
    int size=edges.size();
    for (int i = 0; i<size;i++){
        this->edges[nodeInd][i]=0;
        this->edges[i][nodeInd]=0;
    }
}

bool Graph::isNonVirusFree(int i) {return isNon_virus_free[i]== true;}
void Graph::set_isNonVirusFree(int i) {isNon_virus_free[i]=true;}
void Graph::reset_isNonVirusFree(int i) {isNon_virus_free[i]=false;}


