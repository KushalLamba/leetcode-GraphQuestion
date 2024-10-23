class Solution {
public:
    void dfsfind(int root, vector<vector<int>>& stones, vector<bool>& visited) {
        visited[root] = true;
        int row = stones[root][0];
        int col = stones[root][1];
        for (int i = 0; i < stones.size(); i++) {
            if (!visited[i]) {
                if (row == stones[i][0] || col == stones[i][1]) {
                    dfsfind(i, stones, visited);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int V = stones.size();
        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfsfind(i, stones, visited);
            }
        }
        return V - count;
    }
};