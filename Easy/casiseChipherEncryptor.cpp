using namespace std;

string caesarCypherEncryptor(string str, int key) {
  // Write your code here.
  string res = "";
  for(char c: str){
    res += ((c-'a'+key)%26)+'a';
  }
  return res;
}
