#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int tar) {
  // Write your code here.
  int l = 0, r = arr.size();
  while(l<r){
    int m = (l+r)>>1;
    if(arr[m]<tar) l = m+1;
    else r = m;
  }
  return (arr[l] == tar ? l : -1);
}