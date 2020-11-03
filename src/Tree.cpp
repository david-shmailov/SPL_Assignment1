//
// Created by David on 31/10/2020.
//

#include "../headers/Tree.h"


// abstract Tree:

Tree::Tree(int rootLabel) :node(rootLabel) ,children(){};

Tree::Tree(const Tree &tree) {
    int node;
    std::vector<Tree*> children;
    node = tree.node;
    children = tree.children;
}

Tree * Tree::BFS(const Session &session, int rootLabel) {
    TreeType type = session.getTreeType();
    Tree* tree;
    switch (type) {
        case Root: tree = new RootTree(rootLabel);break;
        case Cycle: tree = new CycleTree(rootLabel,session.)

    }
    Graph g = session.getGraph(); //edges //TODO may need to be deleted
    std::vector<std::vector<int>> edges = g.getMatrix();//edges //TODO make sure this uses copy constructor and does not give a pointer of the original matrix
    std::vector<bool> visited = std::vector<bool>(edges.size(), false);
    std::vector<int> queue;
    visited[rootLabel] = true;
    queue.push_back(rootLabel);
    int visiting;
    while (!queue.empty()) {
        visiting = queue[0];
        queue.erase(queue.begin());
        for (int i = 0; i < edges.size(); i++) {
            if (edges[visiting][i] == 1 && (!visited[i])) {
                queue.push_back(i);
                visited[i] = true;
            }
        }
    }
}





Tree * Tree::createTree(const Session &session, int rootLabel) {
    TreeType type = session.getTreeType();
    switch (type){
        case (Root):
            break;
        case (MaxRank):
            break;
        case (Cycle):
            break;
    }


}

void Tree::addChild(const Tree &child) {
    Tree p = child; //TODO figure out what this error is
    this->children.push_back(&p); //TODO first create a copy constructor for Tree
}




//RootTree:

RootTree::RootTree(int rootLabel): Tree(rootLabel){}

RootTree::RootTree(const RootTree &tree):Tree(tree) {}


int RootTree::traceTree() {return node;}

//copy constructor:
RootTree::RootTree(const RootTree &tree) : {

}


//MaxRankTree:

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel){}


int MaxRankTree::traceTree() {
    MaxRankTree placeholder(5); //
    return this->findMaxRankNode(&placeholder,0); //TODO to implement
}

int MaxRankTree::findMaxRankNode(MaxRankTree *node, int max) {
    int current = 0;
    //current = findMaxRankNode(node->);
}

//CycleTree:

CycleTree::CycleTree(int rootLabel, int currCycle):Tree(rootLabel),currCycle(currCycle) {};

int CycleTree::traceTree() {

};

