#include <unordered_map>
using namespace std;

int firstNonRepeatingCharacter(string string) {
  // Write your code here.
	
	unordered_map<char,int> mp;
	
	for(auto it:string) {
		if(mp.find(it) != mp.end()) {
				 mp[it]++;
			 }
		else {
			mp[it]=0;
		}
		
	}
	
	for(int i=0;i<string.size();i++){
		char character=string[i];
		if(mp[character] == 0)
		{
			return i;
		}
	}
	
  return -1;
}
