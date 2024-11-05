class Solution {
public:
    int maxlen = 0;
    vector<int> cbelow;
    void dfs(int root,vector<vector<int>>& adjlist,
             string& s) {
        int len = 0;
        int maxv1 = 0;
        int maxi = -1;
        for (int i = 0; i < adjlist[root].size(); i++) {
            dfs(adjlist[root][i], adjlist, s);
            if (s[root] != s[adjlist[root][i]]) {
                if (maxv1 < cbelow[adjlist[root][i]]) {
                    maxv1 = max(maxv1, cbelow[adjlist[root][i]]);
                    maxi = adjlist[root][i];
                }
            }
        }
        int maxv2 = 0;
        for (int i = 0; i < adjlist[root].size(); i++) {
            if (maxi != adjlist[root][i] && s[root] != s[adjlist[root][i]])
                maxv2 = max(maxv2, cbelow[adjlist[root][i]]);
        }
        cbelow[root] = maxv1 + 1;
        maxlen = max(maxv1 + maxv2 + 1, maxlen);
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        cbelow.resize(n, 0);
        vector<vector<int>> adjlist(n);
        for (int i = 1; i < n; i++) {
            adjlist[parent[i]].push_back(i);
        }
        dfs(0,adjlist, s);
        return maxlen;
    }
};