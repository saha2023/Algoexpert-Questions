#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> arr) {
  // Write your code here.
  auto cmp = [](auto &a, auto &b){
    return a>b; //ulta operation
  };
  priority_queue<int, vector<int>, decltype(cmp)>pq(cmp);
  int n = arr.size();
  for(int i=0;i< n;i++){
    pq.push(arr[i]);
    if(pq.size()>3) pq.pop();
  }
  vector<int>ans;
  while(pq.size()){
    ans.push_back(pq.top());
    pq.pop();
  }
  return ans;
}
