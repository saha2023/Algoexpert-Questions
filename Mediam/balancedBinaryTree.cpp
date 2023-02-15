using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};

bool flag = true;
int Depth(BinaryTree *root) {
    if (root == nullptr)
        return 0;
    int left = Depth(root->left);
    int right = Depth(root->right);
    if (abs(left - right) > 1) {
        flag = false;
    }
    int myHeight = 1 + max(left, right);
    return myHeight;
}
bool isBalanced(BinaryTree *root) {
    int height = Depth(root);
    return flag;
}

bool heightBalancedBinaryTree(BinaryTree *tree) {
    // Write your code here.
    flag = true;
    return isBalanced(tree);
}