class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> grid(26, vector<long long>(26, LLONG_MAX));
        for (int i = 0; i < original.size(); i++) {
            int o = original[i] - 'a';
            int c = changed[i] - 'a';
            grid[o][c] =
                min(grid[o][c], (long long)cost[i]); // Cast cost to long long
        }

        for (int t = 0; t < 26; t++) {
            for (int row = 0; row < 26; row++) {
                for (int col = 0; col < 26; col++) {
                    if (grid[row][t] != LLONG_MAX &&
                        grid[t][col] != LLONG_MAX) {
                        grid[row][col] =
                            min(grid[row][col], grid[row][t] + grid[t][col]);
                    }
                }
            }
        }

        long long sol = 0;
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int d = target[i] - 'a';
            if (s == d)
                continue;
            if (grid[s][d] == LLONG_MAX)
                return -1;
            sol += grid[s][d];
        }
        return sol;
    }
};