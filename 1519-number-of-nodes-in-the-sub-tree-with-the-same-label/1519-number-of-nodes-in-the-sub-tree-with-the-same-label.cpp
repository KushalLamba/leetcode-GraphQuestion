class Solution {
public:
    vector<int> ans;
    vector<int> count1;
    void dfs(int root, vector<vector<int>>& adjlist, string& s, int parent) {
        int before = count1[s[root] - 'a'];
        count1[s[root] - 'a']++;
        for (int i = 0; i < adjlist[root].size(); i++) {
            int neighbour = adjlist[root][i];
            if (parent != neighbour)
                dfs(adjlist[root][i], adjlist, s, root);
        }
        int after = count1[s[root] - 'a'];
        ans[root] = after - before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        ans.resize(n);
        count1.resize(26, 0);
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        dfs(0, adjlist, s, -1);
        return ans;
    }
};