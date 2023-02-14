class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool validateBst(BST *tree, int min = -1e9, int max = 1e9) {
  // Write your code here.
  if(!tree) return true;
  if(tree->value >= min and tree->value < max){
    return validateBst(tree->left, min, tree->value) and validateBst(tree->right, tree->value, max);
  }
  return false;
}
