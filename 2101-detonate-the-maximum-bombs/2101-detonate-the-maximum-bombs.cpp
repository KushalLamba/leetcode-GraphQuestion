class Solution {
public:
    void dfs(int root, vector<vector<int>>& adjlist, int& count,
             vector<bool>& visited) {
        visited[root] = true;
        count += 1;
        for (int i = 0; i < adjlist[root].size(); i++) {
            int neighbour = adjlist[root][i];
            if (!visited[neighbour])
                dfs(neighbour, adjlist, count, visited);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < n; i++) {
            long long r = bombs[i][2];
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long distance =
                    (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                if (r * r >= distance)
                    adjlist[i].push_back(j);
            }
        }
        int maxcount = 0;
        
        for (int i = 0; i < n; i++) {
                int count = 0;
                vector<bool> visited(n, false);
                dfs(i, adjlist, count, visited);
                maxcount = max(count, maxcount);
        }
        return maxcount;
    }
};