//
// Created by David on 31/10/2020.
//

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix); // constructor
    Graph(const Graph& g);// copy constructor
    virtual ~Graph()=default; // destructor
    Graph(Graph&& other); // move constructor
    const Graph& operator =(const Graph& other);// assignment operator
    const Graph& operator=(Graph&& other);// move assignment operator
    std::vector<std::vector<int>> const getMatrix();
    Graph();////to check delete this constructor

    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    void isolateNode(int nodeInd);

    bool isNonVirusFree(int nodeInd );
    void set_isNonVirusFree(int nodeInd);
    void reset_isNonVirusFree(int i);

private:
    std::vector<std::vector<int>> edges;
    std::vector<bool> infected;
    std::vector<bool> isNon_virus_free;
};

#endif