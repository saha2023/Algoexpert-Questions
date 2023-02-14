using namespace std;

// This is an input class. Do not edit.
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
int dfs(BinaryTree* root, int &maxi){
    if(!root) return -1;
    maxi = max(maxi, dfs(root->left, maxi) + dfs(root->right, maxi) + 2);
    return max(dfs(root->left, maxi), dfs(root->right, maxi)) + 1;
}
int binaryTreeDiameter(BinaryTree *tree) {
  // Write your code here.
  int maxi = -1;
  dfs(tree, maxi);
  return maxi;
}
