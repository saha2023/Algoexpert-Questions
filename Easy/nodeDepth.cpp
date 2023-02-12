using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int nodeDepths(BinaryTree *root, int depth = 0) {
  // Write your code here.
  if(!root) return 0;
  return nodeDepths(root->left, depth+1) + nodeDepths(root->right, depth+1) + depth;
}