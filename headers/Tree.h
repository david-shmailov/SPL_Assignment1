//
// Created by David on 31/10/2020.
//

#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include "Session.h"

class Session;

class Tree{ //role of 5
public:
    Tree(int rootLabel);//constructor
    Tree(const Tree &tree);// copy constructor
    virtual ~Tree();//destructor
    Tree(Tree && other);//move constructor
    const Tree& operator =(const Tree& other);// assignment operator
    const Tree& operator=(Tree&& other);// move assignment operator
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

class CycleTree: public Tree{//role of 5
public:
    CycleTree(int rootLabel, int currCycle);//constructor
    CycleTree(const CycleTree &other);//copy constructor
    virtual ~CycleTree()=default;//destructor
    CycleTree(CycleTree && other);// move constructor
    const CycleTree& operator =(const CycleTree& other)=delete;// assignment operator
    const CycleTree& operator=(CycleTree&& other)=delete;// move assignment operator
    virtual int traceTree();
    static Tree* recTree(std::vector<std::vector<int>> &matrix,int numroot, int cycle);
    virtual Tree& traverse(int num);


private:
    int currCycle;

};

class MaxRankTree: public Tree{//role of 5
public:
    MaxRankTree(int rootLabel);// constructor
    MaxRankTree(const MaxRankTree &other);//copy constructor
    virtual ~MaxRankTree()=default;//destructor
    MaxRankTree(MaxRankTree && other);// move constructor
    const MaxRankTree& operator =(const MaxRankTree& other)=delete;// assignment operator
    const MaxRankTree& operator=(MaxRankTree&& other)=delete;// move assignment operator
    virtual int traceTree();
    static Tree* recTree(std::vector<std::vector<int>> &matrix,int numroot);
    virtual Tree& traverse(int _depth);

};

class RootTree: public Tree{//role of 5
public:
    RootTree(int rootLabel);//copy constructor
    RootTree(const RootTree &other);//copy constructor
    virtual ~RootTree()=default;//destructor
    RootTree(RootTree && other);// move constructor
    const RootTree& operator =(const RootTree& other)=delete;// assignment operator
    const RootTree& operator=(RootTree&& other)=delete;// move assignment operator
    virtual int traceTree();
    static Tree* recTree(std::vector<std::vector<int>> &matrix,int numroot); //TODO consider making this private.
    virtual Tree& traverse(int num);


};

#endif