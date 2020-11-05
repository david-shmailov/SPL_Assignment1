//
// Created by David on 31/10/2020.
//

#include "../headers/Tree.h"


/// abstract Tree:

Tree::Tree(int rootLabel) :node(rootLabel) ,children(){};

Tree::Tree(const Tree &tree) {
    int node;
    std::vector<Tree*> children;
    node = tree.node;
    children = tree.children;
}

int const Tree::getNode(){
    return node;
}

int const Tree::getRank(){return children.size();}

int const Tree::getDepth(){
    return depth;
}

void Tree::setDepth(int _depth){
    depth = _depth;
}



Tree * Tree::createTree(const Session &session, int rootLabel) {

    Graph g = session.getGraph(); //edges //TODO may need to be deleted
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
    //now to construct recursively Tree out of BFSTree matrix
    switch (type) {
        case Root: tree = RootTree::recTree(BFSTree,rootLabel);break;
        case Cycle: tree = CycleTree::recTree(BFSTree,rootLabel,session.getCycle());break;
        case MaxRank: tree = MaxRankTree::recTree(BFSTree,rootLabel);break;
    }//TODO remember to delete this BFS somewhere.

    return tree;
}

void Tree::addChild(const Tree &child) {
    Tree p = child;
    children.push_back(&p);
}




/// RootTree:

RootTree::RootTree(int rootLabel): Tree(rootLabel){}

RootTree::RootTree(const RootTree &tree):Tree(tree) {}

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
Tree& RootTree::traverse(int num) {return *this;}

int RootTree::traceTree() {return node;}




/// MaxRankTree:

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel){}


int MaxRankTree::traceTree() {
    return this->traverse(0).getNode();
}

Tree& MaxRankTree::traverse(int _depth) {

        int maxRank=children.size();
        if (maxRank == 0){ return *this;}
        int minDepth = depth;
        this->depth=_depth;
        Tree& currTree = *this;
        for(int i =0; i<children.size(); i++){
            Tree& nextTree = children[i]->traverse(_depth++);
            if(maxRank  <  nextTree.getRank() || (nextTree.getRank() && minDepth>nextTree.getDepth())){
                minDepth = nextTree.getDepth();
                currTree = nextTree; // TODO attempt to lower traverse times
                maxRank = currTree.getRank();
            }
        }
       return currTree;

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


/// CycleTree:

CycleTree::CycleTree(int rootLabel, int currCycle):Tree(rootLabel),currCycle(currCycle) {};


int CycleTree::traceTree() {
    return this->traverse(currCycle).getNode() ;
};

Tree& CycleTree::traverse(int num) {
    if (this->children[0] && num >0 ) return this->children[0]->traverse(num-1);
    else return *this;
}

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

