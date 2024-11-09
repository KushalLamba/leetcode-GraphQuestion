class Solution {
public:
    int result = 0;
    void dfs(int root, vector<int>& edges, vector<bool>& visited,
             vector<bool>& currvisit, vector<int>& count) {
        if (root != -1) {
            visited[root] = true;
            currvisit[root] = true;
        }
        int v = edges[root];
        if (v != -1 && !visited[v]) {
            count[v] = count[root] + 1;
            dfs(v, edges, visited, currvisit, count);
        } else if (v != -1 && currvisit[v]) {
            result = max(result, count[root] - count[v] + 1);
        }
        currvisit[root] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> currvisit(n, false);
        vector<bool> visited(n, false);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, edges, visited, currvisit, count);
            }
        }
        return result == 0 ? -1 : result;
    }
};