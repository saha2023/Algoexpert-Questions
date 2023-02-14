using namespace std;


bool zeroSumSubarray(vector<int> nums) {
  // Write your code here.
  int sum = 0;
  set<int>st = {0};
  for(auto it: nums){
    sum += it;
    if(st.count(sum)) return 1;
    st.insert(sum);
  }
  return false;
}

