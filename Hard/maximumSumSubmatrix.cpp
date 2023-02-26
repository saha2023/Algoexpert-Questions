#include <vector>
using namespace std;

int maximumSumSubmatrix(vector<vector<int>> mat, int k) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>pref(n+1, vector<int>(m+1, 0));
    // pref = new int [n+1][m+1];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i-1][j-1];
        }
    }

    int maxSum = -1e9;

    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            int sum = pref[i][j] - pref[i][j-k] - pref[i-k][j] + pref[i-k][j-k];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
