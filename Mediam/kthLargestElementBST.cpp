using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};
void dfs(BST* tree, int &k, int &val){
    if(!tree or k==0) return;
    dfs(tree->right, k, val);
    if(k==0) return;
    if(k == 1) val = tree->value;
    k--;
    dfs(tree->left, k, val);
    return;
}
int findKthLargestValueInBst(BST *tree, int k) {
  int val = -1;
  dfs(tree, k, val);
  return val;
}