class Solution {
public:
    typedef pair<int, int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<p>> adjlist(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = abs(points[j][0] - points[i][0]) +
                               abs(points[j][1] - points[i][1]);
                adjlist[i].push_back({j, distance});
                adjlist[j].push_back({i, distance});
            }
        }
        priority_queue<p, vector<p>, greater<p>> minheap;
        minheap.push({0, 0});
        vector<bool> visited(n, false);
        int sum = 0;
        while (!minheap.empty()) {
            int distance = minheap.top().first;
            int node = minheap.top().second;
            minheap.pop();
            if (!visited[node]) {
                visited[node] = true;
                sum += distance;
                for (int i = 0; i < adjlist[node].size(); i++) {
                    int neighbour = adjlist[node][i].first;
                    int neighbourd = adjlist[node][i].second;
                    if (!visited[neighbour]) {
                        minheap.push({neighbourd, neighbour});
                    }
                }
            }
        }
        return sum;
    }
};