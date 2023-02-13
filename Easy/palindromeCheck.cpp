using namespace std;

bool isPalindrome(string str) {
    // 0 1 2 3 4
  int n = str.size();
  int m = (n+1)/2;
  while(m<n){
    if(str[m] != str[n-1-m]) return false;
    m++;
  }
  return true;
}
