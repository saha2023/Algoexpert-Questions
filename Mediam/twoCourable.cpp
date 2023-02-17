using namespace std;

bool twoColorable(vector<vector<int>> edges) {
    // Write your code here.
    enum color {
        NOT_SET,
        RED,
        BLUE
    };
    vector<color> vis(edges.size(), NOT_SET);
    for (int v = 0; v < edges.size(); v++) {
        if (vis[v] == NOT_SET)
            vis[v] = RED;

        for (int child : edges[v]) {
            if (vis[child] != NOT_SET) {
                if (vis[v] == vis[child])
                    return false;
            }
            vis[child] = (vis[v] == RED) ? BLUE : RED;
        }
    }
    return true;
}
