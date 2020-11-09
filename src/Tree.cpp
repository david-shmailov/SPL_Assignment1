//
// Created by David on 31/10/2020.
//

#include "../include/Tree.h"

// abstract Tree:
//////////Tree//////////////
Tree::Tree(int rootLabel) :node(rootLabel) ,children(){};//constructor

Tree::Tree(const Tree &tree):node(tree.node),children() {//copy constructor
    for(auto oldChildren : tree.children) {
        if(oldChildren){
            Tree *t=oldChildren->clone();
            this->children.push_back(t);
        }
    }
}
Tree::Tree(Tree &&other): node(other.node) ,children(other.children){
    other.children.clear();};//move constructor
Tree::~Tree() { //destructor
    for(auto oldChildren : children){
        if(oldChildren){
            delete oldChildren;
        }
    }
    children.clear();
}
const Tree & Tree::operator=(const Tree &other) {//  assignment operator
    if (this!=&other){
        this->node=other.node;
        for(auto oldChildren : children)
            if(oldChildren!=&other)
            delete oldChildren;
        this->children.clear();
        for(auto oldChildren : other.children)
            this->children.push_back(oldChildren);
        return *this;
    }
}
const Tree & Tree::operator=(Tree &&other) {// move assignment operator
    if (this!=&other){
        this->node=other.node;
        std::swap(children,other.children);
        return *this;
    }
}



int  Tree::getNode() const{
    return node;
}

int  Tree::getRank() const {return children.size();}

int  Tree::getDepth() const{
    return depth;
}

void Tree::setDepth(int _depth){
    depth = _depth;
}

Tree * Tree::BFS(const Session &session, int rootLabel){
    Graph g=session.getGraphConst(); //edges
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
        int size=edges.size();
        for (int i = 0; i < size; i++) {
            if (edges[visiting][i] == 1 && (!visited[i])) { //TODO implement the note from the assignment about visit order by indicies
                queue.push_back(i);
                visited[i] = true;
                BFSTree[visiting][i]=1;
                BFSTree[i][visiting]=1;
            }
        }
    }


    return Tree::recTree(BFSTree,rootLabel,session);
}

void Tree::addChild(const Tree &child) {
    Tree* clone = child.clone();
    children.push_back(clone);
}

Tree * Tree::createTree(const Session &session, int rootLabel) {
    switch (session.getTreeType()) {
        case Root:
            return new RootTree(rootLabel);
            break;
        case MaxRank:
            return new MaxRankTree(rootLabel);
            break;
        case Cycle:
            return new CycleTree(rootLabel, session.getCycle());
            break;
    }//TODO remember to make sure this is deleted somewhere.
    return nullptr;
}

Tree* Tree::recTree(std::vector<std::vector<int>> &matrix, int rootLabel,const Session& session) {
    Tree *root= createTree(session,rootLabel);//TODO delete root
    int size=matrix[rootLabel].size();
    for (int j=0; j<size;j++ ){
        if(matrix[rootLabel][j]==1){
            matrix[rootLabel][j]=0;
            matrix[j][rootLabel]=0;
            Tree *t=recTree( matrix,j,session);
            if(t){
                root->addChild(*t);
                delete t;
            }
        }
    }
    return root;
}




/////////////////////////RootTree////////////////////

RootTree::RootTree(int rootLabel): Tree(rootLabel){}//constructor
RootTree::RootTree(const RootTree &tree):Tree(tree) {}//copy constructor
RootTree::RootTree(RootTree &&tree):Tree(tree) {}//move constructor

Tree* RootTree::clone() const {
    RootTree* clone = new RootTree(*this);
    return clone;
}

Tree& RootTree::traverse(int num) {return *this;}

int RootTree::traceTree() {return node;}




//////////////MaxRankTree/////////////////////

MaxRankTree::MaxRankTree(int rootLabel) : Tree(rootLabel){}//constructor
MaxRankTree::MaxRankTree(const MaxRankTree &other):Tree(other) {}//copy constructor
MaxRankTree::MaxRankTree(MaxRankTree &&other):Tree(other) {}//move constructor
int MaxRankTree::traceTree() {
    return this->traverse(0).getNode();
}

Tree& MaxRankTree::traverse(int _depth) {

    int maxRank=children.size();
    if (maxRank == 0){ return *this;}
    int minDepth = depth;
    this->depth=_depth;
    Tree* currTree = this;
    for(unsigned int i =0;i < children.size(); i++){
        Tree& nextTree = children[i]->traverse(_depth++);
        if(maxRank  <  nextTree.getRank() || (nextTree.getRank() && minDepth>nextTree.getDepth())){
            minDepth = nextTree.getDepth();
            currTree = &nextTree; // TODO attempt to lower traverse times
            maxRank = currTree->getRank();
        }
    }
    return *currTree;

}

Tree* MaxRankTree::clone() const {
    MaxRankTree* clone = new MaxRankTree(*this);
    return clone;
}


/////////////CycleTree///////////////////

CycleTree::CycleTree(int rootLabel, int currCycle):Tree(rootLabel),currCycle(currCycle) {};//constructor
CycleTree::CycleTree(const CycleTree &other):Tree(other),currCycle(other.currCycle) {}//copy constructor
CycleTree::CycleTree(CycleTree &&other):Tree(other),currCycle(other.currCycle) {}//move constructor

Tree* CycleTree::clone() const {
    CycleTree* clone = new CycleTree(*this);
    return clone;
}

int CycleTree::traceTree() {
    return this->traverse(currCycle).getNode() ;
};

Tree& CycleTree::traverse(int num) {
    if (this->children[0] && num >0 ) return this->children[0]->traverse(num-1);
    else return *this;
}