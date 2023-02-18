#include <vector>
using namespace std;

vector<vector<int>>twoSum(vector<int>&arr, int start, int end, int tar){
	int i = start, j = end-1;
	vector<vector<int>>ans;
	while(i<j){
		int curr = arr[i] + arr[j];
		if(curr == tar){
			ans.push_back({arr[i], arr[j]});
			i++, j--;
		}
		else if(curr<tar){
			i++;
		}
		else if(curr>tar){
			j--;
		}
	}
	return ans;
}

vector<vector<int>>threeSum(vector<int>&arr, int start, int end, int tar){
	vector<vector<int>>ans;
	// 0 1 2 3 4
	for(int i=start;i<=end-3;i++){
		int newSum = tar-arr[i];
		vector<vector<int>> aubArray = twoSum(arr, i+1, end, newSum);
		for(auto &v: aubArray){
			v.push_back(arr[i]);
			ans.push_back(v);
		}
	}
	return ans;
}

vector<vector<int>> fourNumberSum(vector<int> arr, int tar) {
  // Write your code here.
	sort(arr.begin(), arr.end());
	int n = arr.size();
	vector<vector<int>>ans;
	for(int i = 0; i <= n-4; i++){
		int newSum = tar - arr[i];
		vector<vector<int>> subArray = threeSum(arr, i+1, n, newSum);
		for(auto &v: subArray){
			v.push_back(arr[i]);
			ans.push_back(v);
		}
	}
	return ans;
}
