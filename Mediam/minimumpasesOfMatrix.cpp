#include <vector>
using namespace std;

int minimumPassesOfMatrix(vector<vector<int>> mat) {
    int n = mat.size(), m = mat[0].size();
    deque<array<int,2>>que;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]>0)
                que.push_back({i,j});
        }
    }
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int cnt = -1;
    while(que.size()){
        int sz = que.size(); 
        cnt++;
        while(sz--){
            auto [r, c] = que.front();
            que.pop_front();
            for(auto [dr, dc]: dir){
                if(r+dr>=0 and c+dc>=0 and r+dr<mat.size() and c+dc<mat[0].size() and mat[r+dr][c+dc] < 0){
                    que.push_back({r+dr, c+dc});
                    mat[r+dr][c+dc] = abs(mat[r+dr][c+dc]);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]<0) return -1;
        }
    }
    return cnt;
}
