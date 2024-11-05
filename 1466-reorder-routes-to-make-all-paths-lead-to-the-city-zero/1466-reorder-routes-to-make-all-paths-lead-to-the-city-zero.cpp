class Solution {
public:
    int count1 = 0;
    void dfs(int root, vector<vector<pair<int, int>>>& adjlist, int parent) {
        for (int i = 0; i < adjlist[root].size(); i++) {
            int neighbour = adjlist[root][i].first;
            int real = adjlist[root][i].second;
            if (neighbour != parent) {
                if (real == 1)
                    count1++;
                dfs(neighbour, adjlist, root);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adjlist(n);
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjlist[u].push_back({v, 1});
            adjlist[v].push_back({u, 0});
        }
        dfs(0, adjlist, -1);
        return count1;
    }
};