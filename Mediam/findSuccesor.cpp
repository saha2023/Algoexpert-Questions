using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;
    BinaryTree *parent = nullptr;

    BinaryTree(int value) { this->value = value; }
};

BinaryTree *leftmost(BinaryTree *node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}
BinaryTree *rightmost(BinaryTree *node) {
    while (node->parent and node->parent->right == node) {
        node = node->parent;
    }
    return node->parent;
}
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
    // Write your code here.
    if (node->right) {
        return leftmost(node->right);
    }
    return rightmost(node);
}
