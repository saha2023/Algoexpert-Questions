#include <vector>
using namespace std;
void leftRightTraverser(vector<int>&score, vector<int>&total){
    int n = score.size();
    for(int i = 1;i<n;i++){
        if(score[i] > score[i-1]){
            total[i] = total[i-1] + 1;
        }
    }
}
void rightLeftTraverser(vector<int>&score, vector<int>&total){
    int n = score.size();
    for(int i = n-2; i>=0; i--){
        if(score[i] > score[i+1]){
            total[i] = max(total[i], total[i+1] + 1);
        }
    }
}
int minRewards(vector<int> scores) {
    int n = scores.size();
    vector<int>total(n,1);
    leftRightTraverser(scores, total);
    rightLeftTraverser(scores, total);
    int sum = 0;
    for(int it: total) sum+=it;
    return sum;
}
