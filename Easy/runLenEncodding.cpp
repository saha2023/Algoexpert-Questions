using namespace std;

string runLengthEncoding(string str) {
  // Write your code here.
  string res = "";
  int i = 0;
  int n = str.size();
  int num;
  while(i<n){
    num = 0;
    char prev = str[i];
    do{
        num += 1;
        i++;
    }
    while(prev == str[i] and num<9);
    res += (to_string(num) + prev);
  }
  return res;
}
