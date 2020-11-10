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
    ///rule of 5
    Tree(int rootLabel);//constructor
    Tree(const Tree &tree);// copy constructor
    virtual ~Tree();//destructor
    Tree(Tree && other);//move constructor
    const Tree& operator =(const Tree& other);// assignment operator
    const Tree& operator=(Tree&& other);// move assignment operator TODO make sure const is at the right position


    ///Getters:
    int  getRank() const;
    int  getNode() const;
    int  getDepth() const;

    ///Setters:
    void setDepth(int _depth);
    void addChild(const Tree& child);

    ///static functions:
    static Tree* recTree(std::vector<std::vector<int>> &matrix,int rootLabel, const Session& session); //TODO consider making this private.
    static Tree* createTree(const Session& session, int rootLabel);
    static Tree* BFS(const Session&, int rootLabel);

    ///virtual functions:

    virtual Tree& traverse(int _depth)=0;
    virtual int traceTree()=0; //
    virtual Tree* clone() const =0;


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
    virtual Tree& traverse(int num);
    virtual Tree* clone() const;


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
    virtual Tree& traverse(int _depth);
    virtual Tree* clone() const;

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
    virtual Tree& traverse(int num);
    virtual Tree* clone() const;

};

#endif