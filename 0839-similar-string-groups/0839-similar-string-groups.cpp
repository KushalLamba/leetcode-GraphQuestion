class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x], parent);
    }
    void unionf(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] > rank[y_parent])
            parent[y_parent] = x_parent;
        else if (rank[y_parent] > rank[x_parent])
            parent[x_parent] = y_parent;
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                bool value = false;
                int count = 0;
                for (int k = 0; k < strs[j].size(); k++) {
                    if (strs[i][k] != strs[j][k])
                        count++;
                }
                if (count == 0 || count == 2)
                    value = true;
                if (value)
                    unionf(i, j, parent, rank);
            }
        }
        unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            set.insert(find(i, parent));
        }
        return set.size();
    }
};