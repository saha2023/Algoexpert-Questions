#include <vector>
using namespace std;

int minNumberOfJumps(vector<int> arr) {
  // Write your code here.
    int n = arr.size();
    if(n == 1) return 0;
    int currentMaxIdx = arr[0];
    int nextMaxIdx = arr[0];
    int jump = 1;
    for(int i=0;i<n;i++){
        if(i>currentMaxIdx){
            currentMaxIdx = nextMaxIdx;
            jump++;
        }
        nextMaxIdx = max(nextMaxIdx, arr[i]+i);
    }
    return jump;
}
