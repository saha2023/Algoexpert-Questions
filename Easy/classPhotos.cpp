#include <vector>
using namespace std;

bool classPhotos(vector<int> red, vector<int> blue) {
  // Write your code here.
  sort(red.begin(), red.end()); sort(blue.begin(), blue.end());
  if(red[0]<blue[0]) swap(red, blue);
  int n = red.size();
  for(int i=0;i<n;i++){
    if(red[i]<=blue[i]) return false;
  }
  return true;
}