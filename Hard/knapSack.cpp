#include <vector>
using namespace std;

void knapsack(int idx, int maxValue, int capacity, vector<vector<int>>&res, vector<int>&selItem, vector<vector<int>>&items){
    if(idx==-1 and (maxValue>res[0][0])){
        res[0][0] = maxValue;
        res[1] = selItem;
        return;
    }
    if(capacity<0 or idx<0) return;
    if(capacity>=items[idx][1]){
        selItem.push_back(idx);
        knapsack(idx-1, maxValue+items[idx][0], capacity - items[idx][1], res, selItem, items);
        selItem.pop_back();
    }
    knapsack(idx-1, maxValue, capacity, res, selItem, items);
}


vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
    vector<vector<int>> res = {{0},{}};
    vector<int>selItem;
    knapsack(items.size()- 1, 0, capacity, res, selItem, items);
    return res;
}
