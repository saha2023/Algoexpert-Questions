#include <vector>
using namespace std;
int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int dfs(vector<vector<int>>&mat, int i, int j){
    if(i<0 or j<0 or i>=mat.size() or j>=mat[0].size() or mat[i][j] == 0) return 0;
    int cnt = 1;
    mat[i][j] = 0;
    for(auto &[dr, dc]: dir){
        cnt += dfs(mat, i+dr, j+dc);
    }
    return cnt;
}
vector<int> riverSizes(vector<vector<int>> mat) {
    int n = mat.size(), m = mat[0].size();
    vector<int>res;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1){
                res.push_back(dfs(mat, i, j));
            }
        }
    }
    return res;
}
