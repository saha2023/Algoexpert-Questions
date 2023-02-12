#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  // Write your code here.
  sort(begin(coins), end(coins));
  int sum = 0;
  for(auto &it: coins){
    if(it>(sum+1)){
      return sum+1;
    }
    sum += it;
  }
  return sum+1;
}

