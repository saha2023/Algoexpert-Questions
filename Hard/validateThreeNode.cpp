using namespace std;

// This is an input class. Do not edit.
class BST {
public:
    int value;
    BST *left = nullptr;
    BST *right = nullptr;

    BST(int value) { this->value = value; }
};
bool isDecendent(BST *parrent, BST *child){
    auto current = parrent;
    while(current){
        if(current == child) return true;
        current = child->value >= current->value ? current->right : current->left;
    }
    return false;
}
bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
    if(isDecendent(nodeOne, nodeTwo)){
        return isDecendent(nodeTwo, nodeThree);
    }
    else if(isDecendent(nodeThree, nodeTwo)){
        return isDecendent(nodeTwo, nodeOne);
    }
    return false;
}
