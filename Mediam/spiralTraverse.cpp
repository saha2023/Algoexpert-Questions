using namespace std;
vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size()-1, m = mat[0].size()-1;
        int top = 0, right = m, bottom = n, left = 0;
        int dir = 4;
        vector<int>v;
        int cnt = 0;
        while(left<=right and top<=bottom){
            if(dir % 4 == 0){
                for(int i=left;i<=right;i++){
                    v.push_back(mat[top][i]);
                    cnt++;
                }
                dir++;
                top++;
            }
            else if(dir % 4 == 1){
                for(int i=top;i<=bottom;i++){
                    v.push_back(mat[i][right]);
                    cnt++;
                }
                right--;
                dir++;
            }
            else if(dir % 4 == 2){
                for(int i=right;i>=left;i--){
                    v.push_back(mat[bottom][i]);
                    cnt++;
                }
                bottom--;
                dir++;
            }
            else if(dir % 4 == 3){
                for(int i=bottom;i>=top;i--){
                    v.push_back(mat[i][left]);
                    cnt++;
                }
                dir++;
                left++;
            }
        }
        return v;
    }

vector<int> spiralTraverse(vector<vector<int>> array) {
  // Write your code here.
  return spiralOrder(array);
}