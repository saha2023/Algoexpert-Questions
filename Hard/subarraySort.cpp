#include <vector>
using namespace std;

vector<int> subarraySort(vector<int> array) {
    int n = array.size();

    int minimumDisplacedElement = 1e9;  //smallest number that is displaced
    int maximumDisplacedElement = 0 ; //largest number that is displaced
    for(int i=0;i<n;i++){
        if(i>0 and array[i] < array[i-1]) minimumDisplacedElement = min(minimumDisplacedElement, array[i]);
        if(i+1<n and array[i] > array[i+1]) maximumDisplacedElement = max(maximumDisplacedElement, array[i]);
    }

    int left = -1;
    int right = -1;

    for(int i=0;i<n;i++){
        if(array[i] > minimumDisplacedElement) {left = i;  break;};
    }

    for(int i=n-1;i>=0;i--){
        if(array[i] < maximumDisplacedElement) {right = i;  break;};
    }
    vector<int>v = {left, right}; 
    return v;
}
