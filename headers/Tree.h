//
// Created by David on 31/10/2020.
//

#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include "Session.h"

class Session;

class Tree{
public:
    Tree(int rootLabel);
    Tree(const Tree &tree);
    void addChild(const Tree& child);

    int const getRank();
    static Tree* createTree(const Session& session, int rootLabel);
    int const getNode();
    virtual Tree& traverse(int _depth)=0; //TODO reconsider the decision to make this a public Tree method

    virtual int traceTree()=0; //TODO


    int const getDepth();
    void setDepth(int _depth);



protected:  //Dolav said we can change this to protected
    int node;
    int depth=0;
    std::vector<Tree*> children;


};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    static Tree* recTree(std::vector<std::vector<int>> &matrix,int numroot, int cycle);
    virtual Tree& traverse(int num);


private:
    int currCycle;

};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    static Tree* recTree(std::vector<std::vector<int>> &matrix,int numroot);
    virtual Tree& traverse(int _depth);

};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    RootTree(const RootTree &tree);
    virtual int traceTree();
    static Tree* recTree(std::vector<std::vector<int>> &matrix,int numroot); //TODO consider making this private.
    virtual Tree& traverse(int num);


};

#endif