class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjlist;
        for (int i = 0; i < times.size(); i++) {
            adjlist[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        set<pair<int, int>> set;
        set.insert({0, k});
        vector<int> result(n + 1, INT_MAX);
        result[k] = 0;
        while (!set.empty()) {
            auto& it = *set.begin();
            int dis = it.first;
            int node = it.second;
            set.erase(it);
            for (auto& front : adjlist[node]) {
                int neighbour = front.first;
                int neigdist = front.second;
                if (neigdist + dis < result[neighbour]) {
                    if (result[neighbour] == INT_MAX)
                        set.erase({result[neighbour], neighbour});
                    result[neighbour] = neigdist + dis;
                    set.insert({result[neighbour], neighbour});
                }
            }
        }
        int maxv = 0;
        for (int i = 1; i <= n; i++) {
            if (result[i] == INT_MAX)
                return -1;
            maxv = max(maxv, result[i]);
        }
        return maxv;
    }
};