using namespace std;

bool generateDocument(string characters, string document) {
  // Write your code here.
  int n = characters.size(); int m = document.size();
  if(n < m) return false;
  unordered_map<char, int>mp;
  for(char c: characters) mp[c]++;

  for(char c: document){
    mp[c]--;
    if(mp[c]<0) return false;
  }
  return true;
}
