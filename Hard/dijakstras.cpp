#include <vector>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
    int n = size(edges);
    vector<int>dis(n, 1e9);
    using ppi = pair<int,int>;
    priority_queue<ppi, vector<ppi>, greater<ppi>>pq;
    pq.push({0, start});
    dis[start] = 0;
    while(pq.size()){
        auto [wsf, u] = pq.top();
        pq.pop();
        for(vector<int> edge: edges[u]){
            int v = edge[0];
            int w = edge[1];
            if(wsf+w < dis[v]){
                dis[v] = wsf+w;
                pq.push({dis[v], v});
            }
        }
    }

    for(int &it: dis) if(it == 1e9) it = -1;

    return dis;
}