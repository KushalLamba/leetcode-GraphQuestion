class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjlist(n);
        vector<int> indegree(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adjlist[graph[i][j]].push_back(i);
            }
            indegree[i] += graph[i].size();
        }
        queue<int> pendingnodes;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                pendingnodes.push(i);
                result.push_back(i);
            }
        }
        while (!pendingnodes.empty()) {
            int front = pendingnodes.front();
            pendingnodes.pop();
            for (int i = 0; i < adjlist[front].size(); i++) {
                int neighbour = adjlist[front][i];
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    pendingnodes.push(neighbour);
                    result.push_back(neighbour);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};