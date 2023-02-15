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
BinaryTree* dfs(BinaryTree* one, BinaryTree* two){
    if(!one or !two) return one ? one : two;
    one->value += two->value;
    one->left = dfs(one->left, two->left);
    one->right = dfs(one->right, two->right);
    return one;
}
BinaryTree *mergeBinaryTrees(BinaryTree *tree1, BinaryTree *tree2) {
    // Write your code here.
    dfs(tree1, tree2);
    return tree1;
}
