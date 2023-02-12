#include <vector>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions, vector<int> results) {
  // Write your code here.
  map<string, int> mp;
  int n = results.size();
  int maxi = 0;
  string res;
  for(int i=0;i<n;i++){
    string curr = competitions[i][!results[i]];
    mp[curr]++;
    if(mp[curr]>maxi){
      res = curr;
      maxi = mp[curr];
    }
  }
  return res;
}