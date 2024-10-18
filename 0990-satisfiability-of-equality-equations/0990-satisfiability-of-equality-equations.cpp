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
    bool equationsPossible(vector<string>& s) {
        vector<int> parent(26, -1);
        vector<int> rank(26, 0);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        for (int i = 0; i < s.size(); i++) {
            if (s[i][1] == '=') {
                unionf(s[i][0] - 'a', s[i][3] - 'a', parent, rank);
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i][1] == '!') {
                int x_parent = find(s[i][0] - 'a', parent);
                int y_parent = find(s[i][3] - 'a', parent);
                if (x_parent == y_parent)
                    return false;
            }
        }
        return true;
    }
};