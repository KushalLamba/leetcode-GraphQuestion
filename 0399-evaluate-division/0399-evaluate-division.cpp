class Solution {
public:
    bool dfs(string root, string& end,
             unordered_map<string, vector<pair<string, double>>>& adjlist,
             double& adder, unordered_set<string>& visited) {
        if (root == end)
            return true;

        visited.insert(root);

        for (auto& neighbor : adjlist[root]) {
            string neighbour = neighbor.first;
            double value = neighbor.second;

            if (visited.find(neighbour) == visited.end()) {
                adder *= value;
                if (dfs(neighbour, end, adjlist, adder, visited))
                    return true;
                adder /= value;
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adjlist;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double value1 = values[i];
            double value2 = 1 / value1;

            adjlist[u].push_back({v, value1});
            adjlist[v].push_back({u, value2});
        }

        vector<double> ans(queries.size(), -1.0);

        for (int i = 0; i < queries.size(); i++) {
            string start = queries[i][0];
            string end = queries[i][1];

            if (adjlist.find(start) == adjlist.end() ||
                adjlist.find(end) == adjlist.end()) {
                ans[i] = -1.0;
            } else {
                double adder = 1.0;
                unordered_set<string> visited;
                if (dfs(start, end, adjlist, adder, visited)) {
                    ans[i] = adder;
                }
            }
        }

        return ans;
    }
};