class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adjlist(n);
        vector<int> distance(n, INT_MAX);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int d = flights[i][2];
            adjlist[u].push_back({v, d});
        }
        distance[src] = 0;
        queue<pair<int, int>> pendingnodes;
        pendingnodes.push({src, 0});
        int minrate = INT_MAX;
        while (k >= 0 && !pendingnodes.empty()) {
            int size1 = pendingnodes.size();
            for (int i = 0; i < size1; i++) {
                int root = pendingnodes.front().first;
                int dis = pendingnodes.front().second;
                pendingnodes.pop();
                for (int i = 0; i < adjlist[root].size(); i++) {
                    int neighbour = adjlist[root][i].first;
                    int ndis = adjlist[root][i].second;
                    if (distance[neighbour] > ndis + dis) {
                        distance[neighbour] = dis + ndis;
                        pendingnodes.push({neighbour, distance[neighbour]});
                    }
                }
            }
            k--;
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};