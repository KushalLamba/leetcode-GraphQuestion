class Solution {
public:
    vector<int> parenta;
    vector<int> ans;

    int countnodes(int root, vector<vector<int>>& adjlist) {
        int count = 1;
        for (int i = 0; i < adjlist[root].size(); i++) {
            count += countnodes(adjlist[root][i], adjlist);
        }
        ans[root] = count;
        return count;
    }

    void dfs(int root, vector<vector<int>>& adjlist, string& s,
             unordered_map<char, vector<int>>& mp, vector<int>& parent) {

        char key = s[root];
        if (mp.find(key) != mp.end() && !mp[key].empty()) {
            parenta[root] = mp[key].back();
        } else
            parenta[root] = parent[root];
        mp[s[root]].push_back(root);
        for (int i = 0; i < adjlist[root].size(); i++) {
            dfs(adjlist[root][i], adjlist, s, mp, parent);
        }
        mp[s[root]].pop_back();
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        ans.resize(n);
        parenta.resize(n, -1);
        unordered_map<char, vector<int>> mp;
        vector<vector<int>> adjlist(n);
        vector<vector<int>> nadjlist(n);

        for (int i = 1; i < n; i++) {
            adjlist[parent[i]].push_back(i);
        }
        dfs(0, adjlist, s, mp, parent);
        for (int i = 1; i < n; i++) {
            nadjlist[parenta[i]].push_back(i);
        }
        countnodes(0, nadjlist);
        return ans;
    }
};