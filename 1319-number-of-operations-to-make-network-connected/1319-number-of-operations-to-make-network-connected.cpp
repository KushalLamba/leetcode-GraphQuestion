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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count = 0;
        vector<int> parent(n, -1);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (int i = 0; i < connections.size(); i++) {
            int x_parent = find(connections[i][0], parent);
            int y_parent = find(connections[i][1], parent);
            if (x_parent == y_parent)
                count++;
            else {
                unionf(x_parent, y_parent, parent, rank);
            }
        }
        int need = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                need++;
        }
        if (need - 1 > count)
            return -1;
        return need-1;
    }
};