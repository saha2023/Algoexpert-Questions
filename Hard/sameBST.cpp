#include <vector>

using namespace std;
vector<int>smallerElements(vector<int>&array){
    int n = array.size();
    vector<int>ans;
    for(int i=1;i<n;i++){
        if(array[i]<array[0]) ans.push_back(array[i]);
    }
    return ans;
}
vector<int>largerElements(vector<int>&array){
    int n = array.size();
    vector<int>ans;
    for(int i=1;i<n;i++){
        if(array[i]>=array[0]) ans.push_back(array[i]);
    }
    return ans;
}
bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
    if(arrayOne.size() != arrayTwo.size()) return false;
    if(arrayOne.size() == 0 and arrayTwo.size() == 0) return true;
    if(arrayOne[0] != arrayTwo[0]) return false;

    vector<int>leftSubTreeOne = smallerElements(arrayOne);
    vector<int>leftSubTreeTwo = smallerElements(arrayTwo);
    vector<int>rightSubTreeOne = largerElements(arrayOne);
    vector<int>rightSubTreeTwo = largerElements(arrayTwo);

    return sameBsts(leftSubTreeOne, leftSubTreeTwo) and sameBsts(rightSubTreeOne, rightSubTreeTwo);
}
