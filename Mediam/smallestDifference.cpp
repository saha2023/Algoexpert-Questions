#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> one, vector<int> two) {
  // Write your code here.
  int n = one.size(), m = two.size();
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());
  int a = 0, b = 0;
  int diff = 1e9;
  int num1; int num2;

  while(a< n and b<m){
    int curr_diff = abs(one[a] - two[b]);
    if(curr_diff < diff){
        diff = curr_diff;
        num1 = one[a];
        num2 = two[b];
    }
    if(one[a]<two[b]) a++;
    else b++;
  }
  vector<int>res = {num1, num2};
  return res;
}
