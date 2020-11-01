//
// Created by David on 31/10/2020.
//

#include "../headers/Graph.h"
#include <vector>
// TODO test this
Graph::Graph(std::vector<std::vector<int>> matrix):edges(matrix) {
    //edges = matrix;
    infected = std::vector<bool> (edges.size(),false);
}

bool Graph::isInfected(int nodeInd) {
    return this->infected[nodeInd];
}

void Graph::infectNode(int nodeInd) {
    this->infected[nodeInd] = true;
}




