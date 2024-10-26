class Solution {
public:
    int root_sol = 0;
    vector<int> result;
    int N = 0;
    vector<int> children;
    int dfshelper(int root, vector<vector<int>>& adjlist, int count,
                  int parent) {
        int sol = 1;
        root_sol += count;
        for (int i = 0; i < adjlist[root].size(); i++) {
            if (parent != adjlist[root][i])
                sol += dfshelper(adjlist[root][i], adjlist, count + 1, root);
        }
        children[root] = sol;
        return sol;
    }
    void dfs(int root, vector<vector<int>>& adjlist, int parent) {
        for (int i = 0; i < adjlist[root].size(); i++) {
            int neighbour = adjlist[root][i];
            if (parent != neighbour) {
                result[neighbour] = result[root] + N - 2 * children[neighbour];
                dfs(neighbour, adjlist, root);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        result.resize(n);
        children.resize(n);
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        dfshelper(0, adjlist, 0, -1);
        result[0] = root_sol;
        dfs(0, adjlist, -1);
        return result;
    }
};