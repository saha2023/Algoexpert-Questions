using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
    int value;
    BinaryTree *left = nullptr;
    BinaryTree *right = nullptr;

    BinaryTree(int value) { this->value = value; }
};
void rootNodePath(BinaryTree *tree, int tar, vector<BinaryTree *> &path) {
    if (!tree)
        return;
    if (tree->value == tar) {
        path.push_back(tree);
        return;
    }
    rootNodePath(tree->left, tar, path);
    if (path.size()) {
        path.push_back(tree);
        return;
    }

    rootNodePath(tree->right, tar, path);
    if (path.size()) {
        path.push_back(tree);
        return;
    }
}
void kDown(BinaryTree *root, int k, vector<int> &ans, BinaryTree *block) {
    if (!root or root == block)
        return;
    if (k == 0)
        ans.push_back(root->value);
    kDown(root->left, k - 1, ans, block);
    kDown(root->right, k - 1, ans, block);
}
vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k) {
    vector<BinaryTree *> path;
    rootNodePath(tree, target, path); // i have root to node path
    // now k down node;
    BinaryTree *block = NULL;
    vector<int> ans;
    for (int i = 0; i < path.size(); i++) {
        kDown(path[i], k - i, ans, block);
        block = path[i];
    }
    return ans;
}
