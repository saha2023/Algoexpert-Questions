#include <any>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
// If you know an element of the array is vector<any> you can cast it using:
//     any_cast<vector<any>>(element)
// If you know an element of the array is an int you can cast it using:
//     any_cast<int>(element)
int recc(vector<any> array, int depth, int sum){

  if(array[0].type() == typeid(int)) sum += any_cast(array[0]);
  else{
    sum += recc(any_cast<vector<any>>(array[0]), depth+1, 0))*(depth+1);
  }
  vector<any>arr(array.begin()+1, array.end());
  return recc(arr, depth, sum);
}
int productSum(vector<any> array) {
  // Write your code here.
  return recc(array, 1, 0);
}
