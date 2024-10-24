class Solution {
public:
    int m = 0;
    int n = 0;

    void helper(vector<vector<char>>& maze, vector<vector<bool>>& visited,
                int currrow, int currcol, queue<pair<int, int>>& pendingnodes) {
        if (currrow + 1 < m && maze[currrow + 1][currcol] == '.' &&
            !visited[currrow + 1][currcol]) {
            pendingnodes.push({currrow + 1, currcol});
            visited[currrow + 1][currcol] = true;
        }
        if (currrow - 1 >= 0 && maze[currrow - 1][currcol] == '.' &&
            !visited[currrow - 1][currcol]) {
            pendingnodes.push({currrow - 1, currcol});
            visited[currrow - 1][currcol] = true;
        }
        if (currcol + 1 < n && maze[currrow][currcol + 1] == '.' &&
            !visited[currrow][currcol + 1]) {
            pendingnodes.push({currrow, currcol + 1});
            visited[currrow][currcol + 1] = true;
        }
        if (currcol - 1 >= 0 && maze[currrow][currcol - 1] == '.' &&
            !visited[currrow][currcol - 1]) {
            pendingnodes.push({currrow, currcol - 1});
            visited[currrow][currcol - 1] = true;
        }
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        m = maze.size();
        n = maze[0].size();
        int level = 0;
        queue<pair<int, int>> pendingnodes;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        pendingnodes.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        while (!pendingnodes.empty()) {
            int size1 = pendingnodes.size();
            for (int i = 0; i < size1; i++) {
                int currrow = pendingnodes.front().first;
                int currcol = pendingnodes.front().second;
                pendingnodes.pop();

                if ((currrow == 0 || currrow == m - 1 || currcol == 0 ||
                     currcol == n - 1) &&
                    !(currrow == entrance[0] && currcol == entrance[1])) {
                    return level;
                }

                helper(maze, visited, currrow, currcol, pendingnodes);
            }
            level++;
        }
        return -1;
    }
};