using namespace std;

int longestPeak(vector<int> arr) {
  // Write your code here.
  int n = arr.size();
  int i = 1;
  int maxi = 0;
  int len;
  while(i<n-1){
    len = 1;
    int l = i, r = i;
    if(arr[i]<=arr[i-1] or arr[i]<=arr[i+1]) {i ++ ; continue;}
    while(l>0 and arr[l-1]<arr[l]){
      l--, len++;
    }
    while(r<n-1 and arr[r]>arr[r+1]){
      r++, len++;
    }
    maxi = max(maxi, len);
    i = r+1;
  }
  return maxi;
}
