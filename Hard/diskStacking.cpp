#include <vector>
using namespace std;

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
    sort(begin(disks), end(disks));
    int n = size(disks);
    vector<int>ht(n, 0);
    vector<int>idx(n,-1);
    int maxHeight = 0;
    for(int i=0;i<n;i++){
        ht[i] = disks[i][2];
        for(int j=0;j<i;j++){
            if(ht[j]+disks[i][2] > ht[i] and disks[i][0] > disks[j][0] and disks[i][1] > disks[j][1] and disks[i][2] > disks[j][2]){
                idx[i] = j;
                ht[i] = ht[j] + disks[i][2];
            }
        }
    }
    int maxIdx = distance(ht.begin(), max_element(ht.begin(), ht.end()));
    vector<vector<int>>ans;
    ans.push_back(disks[maxIdx]);
    while(maxIdx != -1){
        int nextIdx = idx[maxIdx];
        if(nextIdx == -1) break;
        ans.push_back(disks[nextIdx]);
        maxIdx = nextIdx;
    }
    reverse(begin(ans), end(ans));
    return ans;
}
