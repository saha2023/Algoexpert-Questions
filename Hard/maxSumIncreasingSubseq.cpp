#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> arr) {
    int n = arr.size();
    vector<int>sum(n, 0);
    vector<int>sequence(n, -1);
    for(int i = 0; i < n; i++){
        sum[i] = arr[i];
        int maxSum = 0;
        for(int j = 0; j <i; j++){
            if(arr[j] < arr[i] and sum[j] > maxSum){
                maxSum = sum[j];
                sequence[i] = j;
            }
        }
        sum[i] += maxSum;
    }

    int maxSumIdx = distance(sum.begin(), max_element(sum.begin(), sum.end()));
    int maxSum = sum[maxSumIdx];

    vector<int>tmp;
    tmp.push_back(arr[maxSumIdx]);
    
    while(maxSumIdx != -1){
        int nextIdx = sequence[maxSumIdx];
        if(nextIdx == -1) break;
        tmp.push_back(arr[nextIdx]);
        maxSumIdx = nextIdx;
    }
    reverse(tmp.begin(), tmp.end());

    vector<vector<int>>ans;
    ans = {{maxSum},{tmp}};
    return ans;
}
