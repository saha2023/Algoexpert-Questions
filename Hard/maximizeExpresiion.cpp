//maximise profit with k=2 transiction

#include <vector>
using namespace std;
int total(vector<int> &arr, int idx, int state, int k) {
    if (idx >= arr.size() or k == 0) {
        if (k == 0)
            return 0; // i got ans
        return -1e9;
    }
    int profit = -1e9;
    if (state == 0) {
        profit = max(profit, max(total(arr, idx + 1, 0, k),
                                (int)(total(arr, idx + 1, 1, k) == -1e9 ? -1e9 : arr[idx] + total(arr, idx + 1, 1, k))));
    }
    else if (state == 1) {
        profit = max(profit, max((int)total(arr, idx + 1, 1, k),
                                (int)(total(arr, idx + 1, 0, k - 1) == -1e9 ? -1e9 : -arr[idx] + (int)total(arr, idx + 1, 0, k - 1))));
    }
    return profit;
}
int maximizeExpression(vector<int> arr) {
    // Write your code here.
    int res = total(arr, 0, 0, 2);
    return res <= -1e9 ? 0 : res;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!----------------------------------------------------------
// aproach 2
#include <vector>
using namespace std;

int maximizeExpression(vector<int> arr) {
    // Write your code here.
    int n = arr.size();
    vector<int> a;
    vector<int> ab;
    vector<int> abc;
    vector<int> abcd;
    ab.push_back(-1e9), abc.push_back(-1e9), abc.push_back(-1e9), abcd.push_back(-1e9), abcd.push_back(-1e9), abcd.push_back(-1e9);
    for (int it : arr) {
        if (a.size() > 0) {
            a.push_back(max(a.back(), it));
        }
        else
            a.push_back(it);
    }
    for (int i = 1; i < n; i++) {
        ab.push_back(max(ab[i - 1], a[i - 1] - arr[i]));
    }
    for (int i = 2; i < n; i++) {
        abc.push_back(max(abc[i - 1], ab[i - 1] + arr[i]));
    }
    for (int i = 3; i < n; i++) {
        abcd.push_back(max(abcd[i - 1], abc[i - 1] - arr[i]));
    }
    return abcd[n - 1] == -1e9 ? 0 : abcd[n - 1];
}
