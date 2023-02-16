#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> arr) {
    int curr = 0;
    int maxi = arr[0];
    for(int it: arr){
        maxi = max(maxi, it);
        curr += it;
        maxi = max(maxi ,curr);
        if(curr < 0) curr = 0;
    }
    return maxi;
}