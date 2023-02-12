using namespace std;

// This is the class of the input root. Do not edit it.
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

void dfs(BinaryTree *root, int sum, vector<int>&ans){
    if(root and !root->left and !root->right){
        ans.push_back(sum+root->value);
        return;
    }
    if(!root){
        return;
    }
    dfs(root->left, sum + root->value, ans);
    dfs(root->right, sum + root->value, ans);
}

vector<int> branchSums(BinaryTree *root) {
  // Write your code here.
  vector<int>ans;
  dfs(root, 0, ans);
  return ans;
}
