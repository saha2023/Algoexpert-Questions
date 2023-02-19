#include <vector>
using namespace std;

vector<int> largestRange(vector<int> arr) {
    unordered_set<int>st;
    for(int it: arr) st.insert(it);
    int left = arr.front(), right = arr.front();
    for(int it: arr){
        if(st.count(it) == 0)
            continue;
        int curr = it;
        int currLeft = curr;
        while(st.count(--curr)){
            st.erase(curr);
            currLeft = curr;
        }
        curr = it;
        int currRight = curr;
        while(st.count(++curr)){
            st.erase(curr);
            currRight = curr;
        }
        if(currRight - currLeft > right - left){
            right = currRight;
            left = currLeft;
        }
    }
    vector<int>v = {left, right};
    return v;
}
