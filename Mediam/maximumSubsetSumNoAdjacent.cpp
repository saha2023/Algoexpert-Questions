#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> arr){
    // Write your code here.
    int n = arr.size();
    vector<int>dp(n,0);
    for(int i=0;i<n;i++){
        int pickmax = arr[i] + (i>=2 ? dp[i-2] : 0);
        int notpickmax = i >= 1 ? dp[i-1] : 0;
        dp[i] = max(pickmax,notpickmax);
    }
    return dp.back();
}

// O(1) space !!!!!!! OPTIMISED
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> arr){
    // Write your code here.
    if(arr.size() == 0) return 0;
    int n = arr.size();
    int curr = 0 ,prev1 = 0, prev2 = 0;
    for(int i=0;i<n;i++){
        int pickmax = arr[i] + (i>=2 ? prev2: 0);
        int notpickmax = (i >= 1 ? prev1 : 0);
        curr = max(pickmax,notpickmax);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
