#include <vector>
using namespace std;

int recc(int tar, vector<int>&arr, int idx){
    if(tar == 0 or idx >= arr.size()) return tar == 0;
    int cnt = 0;
    for(int i=idx;i<arr.size();i++){
        if(tar-arr[i]<0) continue;
        cnt += recc(tar-arr[i],arr,i);
    }
    return cnt;
}

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
    return recc(n, denoms, 0);
    return -1;
}
