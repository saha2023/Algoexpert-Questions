#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> arr) {
  // Write your code here.
  int n = arr.size();
  vector<int>prod(n, 1);
  for(int i = 1;i<n;i++){
    prod[i] = prod[i-1] * arr[i-1];
  }
  int right = 1;
  for(int i = n-2; i>=0; i--){
    right *= arr[i+1];
    prod[i] *= right;
  }
  return prod;
}