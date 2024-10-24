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
        else if (rank[x_parent] < rank[y_parent])
            parent[x_parent] = y_parent;
        else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if (dislikes.size() == 0)
            return true;
        vector<int> parent(2 * n + 1);
        vector<int> rank(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++)
            parent[i] = i;
        for (int i = 0; i < dislikes.size(); i++) {
            int a = dislikes[i][0];
            int b = dislikes[i][1];
            if (find(a, parent) == find(b, parent))
                return false;
            unionf(a + n, b, parent, rank);
            unionf(a, b + n, parent, rank);
        }
        return true;
    }
};