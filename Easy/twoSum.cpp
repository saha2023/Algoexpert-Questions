//Brute Force
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> arr, int tar) {
  // Write your code here.
  int n = arr.size();
  for(int i=0; i<n; i++){
    for(int j = 0; j<n and j != i ; j++){
        if(arr[i]+arr[j] == tar){
            vector<int>ans={arr[i], arr[j]};
            return ans;
        }
    }
  }
  return {};
}


// o(n)->time, O(n)->space
vector<int> twoNumberSum(vector<int> arr, int tar) {
  // Write your code here.
  unordered_set<int>st;
  int n = arr.size();
  for(int i=0; i<n; i++){
    int y = arr[i];
    int x = tar-arr[i];
    if(st.count(x)){
        vector<int>ans = {x,y};
        return ans;
    }
    st.insert(y);
  }
  return {};
}


//O(nlogn)->time , O(1)->Space
vector<int> twoNumberSum(vector<int> arr, int tar) {
  // Write your code here.
  sort(begin(arr), end(arr));
  int i = 0, j = arr.size()-1;
  while(i<j){
    int curr = arr[i] + arr[j];
    if(curr == tar){
        vector<int>ans={arr[i], arr[j]};
        return ans;
    }
    else if(curr < tar){
        i++;
    }
    else j--;
  }
  return {};
}