class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (i == parent[i])
            return i;
        return parent[i] = find(parent[i], parent);
    }
    void unionf(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if (x_parent == y_parent)
            return;
        else {
            if (rank[x_parent] > rank[y_parent])
                parent[y_parent] = x_parent;
            else if (rank[x_parent] < rank[y_parent])
                parent[x_parent] = y_parent;
            else {
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList,
                                           vector<vector<int>>& queries) {
        auto comparator = [&](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        };
        auto comp1 = [&](pair<vector<int>, int>& a, pair<vector<int>, int>& b) {
            return a.first[2] < b.first[2];
        };
        vector<pair<vector<int>, int>> querylist;
        for (int i = 0; i < queries.size(); i++) {
            querylist.push_back({queries[i], i});
        }
        sort(querylist.begin(), querylist.end(), comp1);
        sort(edgeList.begin(), edgeList.end(), comparator);
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int j = 0; j < parent.size(); j++)
            parent[j] = j;
        vector<bool> ans(queries.size(), false);
        int j = 0;
        for (int i = 0; i < querylist.size(); i++) {
            int u = querylist[i].first[0];
            int v = querylist[i].first[1];
            int dis = querylist[i].first[2];
            while (j < edgeList.size() && dis > edgeList[j][2]) {
                unionf(edgeList[j][0], edgeList[j][1], parent, rank);
                j++;
            }
            int x_parent = find(u, parent);
            int y_parent = find(v, parent);
            if (x_parent == y_parent)
                ans[querylist[i].second] = true;
        }
        return ans;
    }
};