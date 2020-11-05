//
// Created by David on 31/10/2020.
//

#include "../headers/Tree.h"
#include "../headers/Session.h"
#include "../headers/Session.h"

// abstract Tree:
//////////Tree//////////////
Tree::Tree(int rootLabel) :node(rootLabel) ,children(){};//constructor

Tree::Tree(const Tree &tree) {//copy constructor
    int node;
    node = tree.node;
    for(auto oldChildren : tree.children)
        children.push_back(oldChildren);
}
Tree::Tree(Tree &&other): node(other.node) ,children(other.children){};//move constructor
Tree::~Tree() { //destructor
    for(auto oldChildren : children)
        delete oldChildren;
    children.clear();
}
const Tree & Tree::operator=(const Tree &other) {//  assignment operator
    node=other.node;
    for(auto oldChildren : children)
        delete oldChildren;
    children.clear();
    for(auto oldChildren : other.children)
        children.push_back(oldChildren);
    return *this;
}
const Tree & Tree::operator=(Tree &&other) {// move assignment operator
    node=other.node;
    std::swap(children,other.children);
    return *this;
}


Tree * Tree::BFS(const Session &session, int rootLabel) {

    Graph g( session.getGraph()); //edges //TODO may need to be deleted
    std::vector<std::vector<int>> edges = g.getMatrix();//edges //TODO make sure this uses copy constructor and does not give a pointer of the original matrix
    std::vector<std::vector<int>> BFSTree(edges.size(), std::vector<int>(edges.size(), 0)); // init 2D nxn matrix of 0s on stack. //TODO make sure this is on stack
    std::vector<bool> visited = std::vector<bool>(edges.size(), false);
    std::vector<int> queue;
    visited[rootLabel] = true;
    queue.push_back(rootLabel);
    int visiting;
    while (!queue.empty()) {
        visiting = queue[0];
        queue.erase(queue.begin());
        for (int i = 0; i < edges.size(); i++) {
            if (edges[visiting][i] == 1 && (!visited[i])) { //TODO implement the note from the assignment about visit order by indicies
                queue.push_back(i);
                visited[i] = true;
                BFSTree[visiting][i]=1;
                BFSTree[i][visiting]=1;
            }
        }
    }
    TreeType type = session.getTreeType();
    Tree* tree;
    switch (type) {
        case Root: tree = RootTree::recTree(BFSTree,rootLabel);break;
        case Cycle: tree = CycleTree::recTree(BFSTree,rootLabel,session.getCycle());break;
        case MaxRank: tree = MaxRankTree::recTree(BFSTree,rootLabel);break;
    }//TODO remember to delete this BFS somewhere.
    //now to construct recursively Tree out of BFSTree matrix
    return tree;
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
    children.push_back(&p); //TODO first create a copy constructor for Tree
}




/////////////////////////RootTree////////////////////

RootTree::RootTree(int rootLabel): Tree(rootLabel){}//constructor
RootTree::RootTree(const RootTree &tree):Tree(tree) {}//copy constructor
RootTree::RootTree(RootTree &&tree):Tree(tree) {}//move constructor

Tree* RootTree::recTree(std::vector<std::vector<int>> &matrix, int numroot) {
    Tree *root= new RootTree(numroot);//TODO delete root
    for (int j=0; j<matrix[numroot].size();j++ ){
        if(matrix[numroot][j]==1){
            matrix[numroot][j]=0;
            matrix[j][numroot]=0;
            Tree *t=recTree( matrix,j);
            root->addChild(*t);
        }
    }
    return root;
}

int RootTree::traceTree() {return node;}




//////////////MaxRankTree/////////////////////

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel){}//constructor
MaxRankTree::MaxRankTree(const MaxRankTree &other):Tree(other) {}//copy constructor
MaxRankTree::MaxRankTree(MaxRankTree &&other):Tree(other) {}//move constructor
int MaxRankTree::traceTree() {
    MaxRankTree placeholder(5); //
    return this->findMaxRankNode(&placeholder,0); //TODO to implement
}

Tree* MaxRankTree::recTree(std::vector<std::vector<int>> &matrix, int numroot) {
    Tree *root= new MaxRankTree(numroot);//TODO delete root
    for (int j=0; j<matrix[numroot].size();j++ ){
        if(matrix[numroot][j]==1){
            matrix[numroot][j]=0;
            matrix[j][numroot]=0;
            Tree *t=recTree( matrix,j);
            root->addChild(*t);
        }
    }
    return root;
}

int MaxRankTree::findMaxRankNode(MaxRankTree *node, int max) {
    int current = 0;
    //current = findMaxRankNode(node->);
}

/////////////CycleTree///////////////////

CycleTree::CycleTree(int rootLabel, int currCycle):Tree(rootLabel),currCycle(currCycle) {};//constructor
CycleTree::CycleTree(const CycleTree &other):Tree(other),currCycle(other.currCycle) {}//copy constructor
CycleTree::CycleTree(CycleTree &&other):Tree(other),currCycle(other.currCycle) {}//move constructor

int CycleTree::traceTree() {

};

Tree* CycleTree::recTree(std::vector<std::vector<int>> &matrix, int numroot, int cycle ) {
    Tree *root= new CycleTree(numroot,cycle);//TODO delete root
    for (int j=0; j<matrix[numroot].size();j++ ){
        if(matrix[numroot][j]==1){
            matrix[numroot][j]=0;
            matrix[j][numroot]=0;
            Tree *t=recTree( matrix,j,cycle);
            root->addChild(*t);
        }
    }
    return root;
}

