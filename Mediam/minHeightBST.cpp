using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};
void recursive(int l, int r, BST* &root, vector<int>&arr){
  if(l>=r) return;
  int m = (l+r)/2;
  if(!root) root = new BST(arr[m]);
  else root->insert(arr[m]);
  recursive(l, m, root, arr);
  recursive(m+1, r, root, arr);
}
BST *minHeightBst(vector<int> arr) {
  // Write your code here.
  BST* root = tmp = nullptr;
  int n = arr.size();
  recursive(0, n, root, arr);
  return tmp;
}
