using namespace std;
bool hasSingleCycle(vector<int> arr) {
    int numberOfElementsVis = 0;
    int currIdx = 0;
    int n = arr.size();
    while(numberOfElementsVis < n){
        if(numberOfElementsVis != 0 and currIdx == 0)
            return false;
        numberOfElementsVis++;
        currIdx += arr[currIdx];
		currIdx = currIdx % n;
		if (currIdx < 0) {
			currIdx = n + currIdx;
		}
    }
    return currIdx == 0;
}