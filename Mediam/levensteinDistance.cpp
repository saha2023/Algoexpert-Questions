using namespace std;
int recc(string &s1, string &s2, int n, int m) {
    if (n == 0 or m == 0) {
        return (n == 0 ? m : n);
    }
    int cnt;
    if (s1[n - 1] == s2[m - 1]) {
        cnt = recc(s1, s2, n - 1, m - 1);
    }
    else {
        cnt = min(recc(s1, s2, n, m - 1), (min(recc(s1, s2, n - 1, m), recc(s1, s2, n - 1, m - 1))));
        //        insert               delete                   replace
        cnt += 1;
    }
    return cnt;
}
int levenshteinDistance(string str1, string str2) {
    // Write your code here.
    int n = str1.size(), m = str2.size();
    return recc(str1, str2, n, m);
}
