class Solution {
private:
    vector<vector<int>>pref2d(vector<vector<int>>&v, int n, int m){
        vector<vector<int>>res(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i+1][j+1] = v[i][j] + res[i+1][j] + res[i][j+1] - res[i][j];
            }
        }
        return res;
    }
    int sumRange(vector<vector<int>>&v, int x1, int y1, int x2, int y2){
        return v[x1+1][y2+1] - v[x2+1][y1] - v[x1][y2+1] + v[x1][y1];
    }
public:
    bool possibleToStamp(vector<vector<int>>& g, int h, int w) {
        int n = g.size(), m = g[0].size();
        auto pref = pref2d(g, n, m);
        vector<vector<int>>stamp(n, vector<int>(m, 0)); // 1 if i am able to put a stamp gracefully
        for(int i=h-1;i<n;i++){
            for(int j=w-1;j<m;j++){
                stamp[i][j] = (sumRange(pref, i-h+1, j-w+1, i, j) == 0);
            }
        }
        auto pref2 = pref2d(stamp, n, m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j] == 0 and sumRange(pref2, i, j, min(i+h-1, n-1), min(j+w-1, m-1)) == 0) return false;
            }
        }
        return true;
    }
};