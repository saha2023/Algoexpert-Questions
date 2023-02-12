class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};
void traverse(BST* root, int tar, int &val){
    if(!root) return;
    if(root->value <= tar){
        if(abs(root->value - tar) < abs(tar - val)) val = root->value;
        traverse(root->right, tar, val);
    }
    else {
        if(abs(root->value - tar) < abs(tar - val)) val = root->value;
        traverse(root->left, tar, val);
    }
}

int findClosestValueInBst(BST *tree, int target) {
  // Write your code here.
  int val = -1e9;
  traverse(tree, target, val);
  return val;
}
