using namespace std;

bool isValidSubsequence(vector<int> arr, vector<int> seq) {
  // Write your code here.
	int start = 0;
	for(int val : arr) 
        start += seq[start] == val;
	return start == seq.size();
}