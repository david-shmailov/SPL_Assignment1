//
// Created by David on 31/10/2020.
//

#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include "session.h"

class Session;

class Tree{
public:
    Tree(int rootLabel);
    Tree(const Tree &tree);
    void addChild(const Tree& child);


    static Tree* createTree(const Session& session, int rootLabel);

    static Tree* BFS(const Session& session, int rootLabel, TreeType type);

    virtual int traceTree()=0;

    int;

protected:  //Dolav said we can change this to protected
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
private:
    int findMaxRankNode(MaxRankTree* node, int max);
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    RootTree(const RootTree &tree);
    virtual int traceTree();
};

#endif