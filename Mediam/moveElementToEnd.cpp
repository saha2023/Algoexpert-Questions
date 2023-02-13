#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> arr, int ele) {
  // Write your code here.
  int i = 0, j = arr.size()-1;
  while(i<j){
    if(arr[i] == ele){
        swap(arr[i], arr[j]);
        j--;
    }
    else i++;
  }
  return arr;
}
