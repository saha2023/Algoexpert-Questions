// given elements in the interns can also be -ve
/**/
#include <vector>
using namespace std;
// -10, -5, 0, 5, 10
// non working code
vector<int> sortedSquaredArray(vector<int> arr) {
  // Write your code here.
  int n = arr.size();
  vector<int>ans(n);
  int i = 0, j = n-1;
  int k = n-1;
  while(i<j){
    int num1 = arr[i]*arr[i];
    int num2 = arr[j]*arr[j];
    if(num1 > num2){
      ans[k] = num1;
      k--; i++;
    }
    else if(num1 < num2){
      ans[k] = num2;
      k--; j--;
    }
    else{
      ans[k--] = num1;
      ans[k--] = num2;
      i++, j--;
    }
  }
  if(k>=0) ans[k] = (arr[i]*arr[i]);
  return ans;
}