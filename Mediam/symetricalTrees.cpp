using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) {
        this->value = value;
    }
};
bool check(BinaryTree *one, BinaryTree *two) {
    if(!one or !two) return !(one == two);
    if(one->value != two->value) return true;
    return check(one->left, two->right) or check(one->right, two->left);
}
bool symmetricalTree(BinaryTree *tree) {
    // Write your code here.
    return !check(tree, tree);
    return false;
}
