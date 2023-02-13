#include <vector>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest) {
  // Write your code here.
  sort(redShirtSpeeds.begin(), redShirtSpeeds.end()); sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
  int n =redShirtSpeeds.size();
  if(fastest) reverse(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
  int total = 0;
  for(int i=0;i<n;i++){
    total += max(redShirtSpeeds[i], blueShirtSpeeds[i]);
  }
  return total;
}
