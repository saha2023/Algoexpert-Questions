#include <vector>
using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2)  {
    // Write your code here.
    vector<vector<string>> lcs(str2.size()+1, vector<string>(str1.size()+1));
    for (int i = 1; i <= str2.length(); i++) {
        for (int j = 1; j <= str1.length(); j++) {
            if (str2[i - 1] == str1[j - 1]) {
                string copy = lcs[i - 1][j - 1];
                copy.push_back(str2[i - 1]);
                lcs[i][j] = copy;
            }
            else {
                lcs[i][j] = lcs[i - 1][j].size() > lcs[i][j - 1].size() ? lcs[i - 1][j] : lcs[i][j - 1];
            }
        }
    }
    vector<char>ans;
    for(char c: lcs[str2.length()][str1.length()]){
        ans.push_back(c);
    }
    return ans;
}
