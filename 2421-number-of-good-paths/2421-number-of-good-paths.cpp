class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x], parent);
    }
    void unionf(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
        else if (rank[y_parent] > rank[x_parent])
            parent[x_parent] = y_parent;
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int count = 0;
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        vector<int> rank(n, 0);
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        map<int, vector<int>> mp;
        for (int i = 0; i < vals.size(); i++) {
            mp[vals[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int key = it->first;
            vector<int> vec = it->second;
            for (int i = 0; i < vec.size(); i++) {
                visited[vec[i]] = true;
            }
            for (int i = 0; i < vec.size(); i++) {
                for (int j = 0; j < adjlist[vec[i]].size(); j++) {
                    int neighbour = adjlist[vec[i]][j];
                    if (visited[neighbour]) {
                        unionf(neighbour, vec[i], parent, rank);
                    }
                }
            }
            unordered_map<int, int> mpc;
            for (int i = 0; i < vec.size(); i++) {
                mpc[find(vec[i], parent)]++;
            }
            for (auto it = mpc.begin(); it != mpc.end(); it++) {
                int val = it->second;
                if (val > 1)
                    count += (val * (val - 1)) / 2;
            }
        }
        return count + n;
    }
};