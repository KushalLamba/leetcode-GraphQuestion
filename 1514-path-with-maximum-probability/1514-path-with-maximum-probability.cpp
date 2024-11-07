class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, double>>> adjlist(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adjlist[u].push_back({v, prob});
            adjlist[v].push_back({u, prob});
        }
        vector<double> result(n, 0.0);
        result[start_node] = 1.0;
        priority_queue<pair<double, int>> pendingnodes;
        pendingnodes.push({1.0, start_node});
        while (!pendingnodes.empty()) {
            int root = pendingnodes.top().second;
            double prob = pendingnodes.top().first;
            pendingnodes.pop();
            if (root == end_node)
                return prob;
            for (int i = 0; i < adjlist[root].size(); i++) {
                int neighbour = adjlist[root][i].first;
                double nprob = adjlist[root][i].second;
                double new_prob = nprob * prob;
                if (new_prob > result[neighbour]) {
                    result[neighbour] = new_prob;
                    pendingnodes.push({result[neighbour], neighbour});
                }
            }
        }
        return result[end_node];
    }
};