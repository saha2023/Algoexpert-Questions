using namespace std;

int minimumWaitingTime(vector<int> queries) {
  // Write your code here.
  int n = queries.size();
  sort(queries.begin(), queries.end());
  int total = 0;
  int sum = 0;
  for(int i=0;i<n;i++){
    total += sum;
    sum += queries[i];
  }
  return total;
}
