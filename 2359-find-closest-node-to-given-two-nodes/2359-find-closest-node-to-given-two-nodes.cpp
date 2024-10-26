class Solution {
public:
    void dfs(int root, vector<int>& edges, vector<int>& result, int count) {
        if(root==-1) return;
        if (result[root] > count) {
            result[root] = count;
            dfs(edges[root], edges, result, count + 1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> result1(n, INT_MAX);
        vector<int> result2(n, INT_MAX);
        dfs(node1, edges, result1, 0);
        dfs(node2, edges, result2, 0);
        int ans = INT_MAX;
        int node=-1;
        for (int i = 0; i < n; i++) {
            int value=max(result1[i], result2[i]);
            if(value<ans)
            {
                ans=value;
                node=i;
            }
        }
        return node;
    }
};