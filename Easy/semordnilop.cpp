using namespace std;


vector<vector<string>> semordnilap(vector<string> words) {
  // Write your code here.
  unordered_map<string, vector<string>>mp;
  for(auto word: words){
    string tmp = word;
    sort(word.begin(), word.end());
    mp[word].push_back(tmp);
  }
  vector<vector<string>>ans;
  for(auto &[key, val]: mp){
    if(val.size() > 1) ans.push_back(val);
  }
  return ans;
}

