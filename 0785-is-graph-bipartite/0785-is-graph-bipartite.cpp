class Solution {
public:
    bool helper(int root, vector<vector<int>>& graph, vector<int>& color,
                int fill) {
        color[root] = fill;
        for (int i = 0; i < graph[root].size(); i++) {
            int neighbour = graph[root][i];
            if (color[neighbour] == -1 &&
                !helper(neighbour, graph, color, 1-fill)) {
                return false;
            }
            if (color[neighbour] != -1 && color[neighbour] == color[root])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1 && !helper(i, graph, color, 0)) {
                return false;
            }
        }
        return true;
    }
};