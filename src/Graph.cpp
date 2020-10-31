//
// Created by David on 31/10/2020.
//

#include "../headers/Graph.h"
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);

    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
private:
    std::vector<std::vector<int>>> edges;
}

#endif
