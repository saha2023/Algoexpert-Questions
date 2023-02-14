#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};
BinaryTree * invert(BinaryTree* &tree){
    if(!tree) return NULL;
    BinaryTree *left = invert(tree->left);
    BinaryTree *right = invert(tree->right);
    tree->left = right;
    tree->right = left;
    return tree;
}
void invertBinaryTree(BinaryTree *tree) {
  // Write your code here.
  return invert(tree);
}
