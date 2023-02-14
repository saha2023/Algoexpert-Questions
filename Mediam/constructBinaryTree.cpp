using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};
int idx = 0;
BST *reconstructBst(vector<int> preOrder, int lr , int rr) {
  // Write your code here.
  if(idx>=preOrder.size() or preOrder[idx] >= rr or preOrder[idx] < lr) return nullptr;
  BST *node = new BST(preOrder[idx++]);
  node->left = reconstructBst(preOrder, lr, node->value);
  node->right = reconstructBst(preOrder, node->value, rr);
  return node;
}

BST *reconstructBst(vector<int> preOrderTraversalValues) {
  // Write your code here.
  idx = 0;
  return reconstructBst(preOrderTraversalValues, -1e9, 1e9);
  return nullptr;
}
