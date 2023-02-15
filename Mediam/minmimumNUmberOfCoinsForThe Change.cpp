#include <vector>
using namespace std;
int mini;
int recc(int tar, vector<int>&arr, int idx, int num){
    if(tar == 0 or idx >= arr.size()){
        mini = min(mini, num);
        return tar == 0;
    }
    int cnt = 0;
    for(int i=idx;i<arr.size();i++){
        if(tar-arr[i]<0) continue;
        cnt += recc(tar-arr[i],arr,i, num+1);
    }
    return cnt;
}
int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    mimi = 1e9;
    recc(n, denoms, 0, 0);
    return mini == 1e9 ? -1 : mini;
}
