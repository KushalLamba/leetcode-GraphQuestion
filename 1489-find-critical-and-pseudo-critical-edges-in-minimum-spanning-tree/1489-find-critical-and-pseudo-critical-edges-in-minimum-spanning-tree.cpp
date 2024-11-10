class Solution {
public:
    int N;
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> rank;
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }
        int find(int x) {
            if (x == parent[x])
                return x;
            return parent[x] = find(parent[x]);
        }
        void unionf(int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);
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
    };
    int kruskel(vector<vector<int>>& edges, int skip, int add) {
        int sum = 0;
        int countedges = 0;
        UnionFind uf(N);
        if (add != -1) {
            uf.unionf(edges[add][0], edges[add][1]);
            sum += edges[add][2];
            countedges++;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (skip == i)
                continue;
            if (uf.find(edges[i][0]) != uf.find(edges[i][1])) {
                uf.unionf(edges[i][0], edges[i][1]);
                sum += edges[i][2];
                countedges++;
            }
        }
        if (countedges != N - 1)
            return INT_MAX;
        return sum;
    }
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        auto compartor = [&](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        };
        vector<int> criticaledge;
        vector<int> pseudocritical;
        sort(edges.begin(), edges.end(), compartor);
        int maxweight = kruskel(edges, -1, -1);
        for (int i = 0; i < edges.size(); i++) {
            if (kruskel(edges, i, -1) > maxweight) {
                criticaledge.push_back(edges[i][3]);
            } else if (kruskel(edges, -1, i) == maxweight) {
                pseudocritical.push_back(edges[i][3]);
            }
        }
        return {criticaledge, pseudocritical};
    }
};