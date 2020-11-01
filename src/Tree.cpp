//
// Created by David on 31/10/2020.
//

#include "../headers/Tree.h"

// abstract Tree:

Tree::Tree(int rootLabel) :node(rootLabel) ,children(){};

Tree * Tree::createTree(const Session &session, int rootLabel) {} //TODO figure out what this suppose to do

void Tree::addChild(const Tree &child) {

}


//RootTree:

RootTree::RootTree(int rootLabel): Tree(rootLabel){}

int RootTree::traceTree() {return node;} //TODO figure out how to access base data




//MaxRankTree:

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel){}


int MaxRankTree::traceTree() {
    MaxRankTree placeholder(5); //TODO figure out how to use self node instead of placeholder
    return this->findMaxRankNode(&placeholder,0);
}

int MaxRankTree::findMaxRankNode(MaxRankTree *node, int max) {
    int current = 0;
    current = findMaxRankNode(node->);

}

