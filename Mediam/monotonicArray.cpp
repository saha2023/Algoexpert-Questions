using namespace std;

bool isMonotonic(vector<int> arr) {
  // Write your code here.
	int increasing = 1;
	int decreasing = 1;
	for(int i=1;i<arr.size();i++){
		if(arr[i]>arr[i-1]) decreasing = 0;
		if(arr[i]<arr[i-1]) increasing = 0;
	}
  return increasing or decreasing;
}
