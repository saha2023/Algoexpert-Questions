
//T->O(n*n)
#include <vector>
using namespace std;
vector<vector<int>>twoSum(vector<int>&arr, int st, int en, int tar){
    int l = st, r = en-1;
    vector<vector<int>>ans;
    while(l<r){
        int curr = arr[l]+arr[r];
        if(curr == tar){
            ans.push_back({arr[l], arr[r]});
            l++, r--;
        }
        else if(curr < tar){
            l++;
        }
        else r--;
    }
    return ans;
}
vector<vector<int>> threeNumberSum(vector<int> arr, int tar) {
  // Write your code here.
  sort(arr.begin(), arr.end());
  int n = arr.size();
  vector<vector<int>>ans;
  for(int i=0;i<=n-3;i++){
    vector<vector<int>>subArr = twoSum(arr, i+1, n, tar-arr[i]);
    for(auto &v: subArr){
        v.push_back(arr[i]);
        sort(v.begin(), v.end()); // 3 log(3) -> constant
        ans.push_back(v);
    }
  }
  return ans;
}