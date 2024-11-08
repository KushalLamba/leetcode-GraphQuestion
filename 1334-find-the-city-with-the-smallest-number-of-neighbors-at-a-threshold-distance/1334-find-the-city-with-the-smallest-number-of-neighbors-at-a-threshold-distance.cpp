class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            grid[u][v] = weight;
            grid[v][u] = weight;
        }

        for (int via = 0; via < n; via++) {
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    if (row == col)
                        continue;
                    if (grid[row][via] != INT_MAX &&
                        grid[via][col] != INT_MAX) {
                        grid[row][col] = min(grid[row][col],
                                             grid[row][via] + grid[via][col]);
                    }
                }
            }
        }
        int mincount = INT_MAX;
        int ans = 0;
        for (int row = 0; row < n; row++) {
            int count = 0;
            for (int col = 0; col < n; col++) {
                if (grid[row][col] <= distanceThreshold)
                    count++;
            }
            if (mincount >= count) {
                mincount = count;
                ans = row;
            }
        }
        return ans;
    }
};