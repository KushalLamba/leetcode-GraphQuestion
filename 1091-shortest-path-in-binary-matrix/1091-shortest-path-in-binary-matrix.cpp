class Solution {
    int n;

    bool isValid(int i, int j, vector<vector<int>>& grid) {
        if (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0)
            return true;
        else
            return false;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(n, -1));

        queue<pair<int, int>> q1;

        if (grid[0][0] == 0) {
            q1.push({0, 0});
            dist[0][0] = 1;
        } else
            return -1;

        vector<int> x = {-1, +1, 0, 0, -1, +1, -1, +1};
        vector<int> y = {0, 0, -1, +1, -1, +1, +1, -1};

        while (!q1.empty()) {
            pair<int, int> curr = q1.front();
            q1.pop();

            for (int k = 0; k < 8; k++) {
                int newX = curr.first + x[k];
                int newY = curr.second + y[k];

                if (isValid(newX, newY, grid) && dist[newX][newY] == -1) {
                    dist[newX][newY] = dist[curr.first][curr.second] + 1;
                    q1.push({newX, newY});
                }
            }
        }

        if (dist[n - 1][n - 1] == -1)
            return -1;

        return dist[n - 1][n - 1];
    }
};