class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         vector<vector<int>> paths;// Initialize an empty vector to store all paths
        vector<int> currentPath;// Initialize an empty vector to store the current path during exploration
        dfs(graph, paths, currentPath, 0);// Start DFS from source node (index 0)
        return paths;// Return the vector containing all found paths
        
    }
    private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& currentPath, int node) {
        currentPath.push_back(node);// Add the current node to the path

        if (node == graph.size() - 1) {// Check if we reached the target node
            paths.push_back(currentPath);// If yes, add the complete path to the results
        } else {
            for (int neighbor : graph[node]) { // Explore all neighbors of the current node
                dfs(graph, paths, currentPath, neighbor);// Recursive call for each neighbor
            }
        }
        currentPath.pop_back(); // Backtrack: Remove the current node from the path
    }
};