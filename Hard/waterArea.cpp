#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
    if(heights.size() == 0) return 0;
    int idx = distance(heights.begin(), max_element(heights.begin(), heights.end()));
    int total = 0;
    int n = heights.size();
    int left = heights.front();
    for(int i = 0; i <=idx; i++){
        if(heights[i] > left) left = heights[i];
        else total += (left - heights[i]);
    }

    int right = heights.back();
    for(int i=n-1;i>=idx;i--){
        if(heights[i] > right) right = heights[i];
        else total += (right - heights[i]);
    }
    return total;
}
