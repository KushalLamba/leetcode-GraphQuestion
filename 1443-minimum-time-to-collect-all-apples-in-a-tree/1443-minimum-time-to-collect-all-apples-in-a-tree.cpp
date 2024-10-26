class Solution {
public:
    int dfs(int root, vector<vector<int>>& adjlist, vector<bool>& hasapple,
            int parent) {
        int time = 0;
        for (int i = 0; i < adjlist[root].size(); i++) {
            int neighbour=adjlist[root][i];
            if (parent != neighbour){
                int ans = dfs(neighbour, adjlist, hasapple, root);
                if(ans>0 || hasapple[neighbour]) time+=ans+2;}
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        return dfs(0, adjlist, hasApple, -1);
    }
};