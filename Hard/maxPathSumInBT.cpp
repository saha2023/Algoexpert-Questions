#include <vector>
using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
};

int recc(BinaryTree *tree, int &maxi) {
    if (tree == NULL) return 0;
    int value = tree->value;
    int left = recc(tree->left, maxi);
    int right = recc(tree->right, maxi);
    int path1 = left + right + value;
    int path2 = left + value;
    int path3 = right + value;
    maxi = max({path1, path2, path3, maxi});
    return max(path2, path3);
}

int maxPathSum(BinaryTree tree) {
    // Write your code here.
    int maxi = (int)-1e9;
    int call = recc(&tree, maxi);
    return maxi;
}
