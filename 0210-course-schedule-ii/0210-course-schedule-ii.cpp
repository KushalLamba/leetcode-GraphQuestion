class Solution {
public:
    bool checkcycle = false;
    void dfstopo(int root, unordered_map<int, vector<int>>& adjlist,
                 vector<bool>& visited, vector<bool>& currvisit,
                 stack<int>& st) {
        visited[root] = true;
        currvisit[root] = true;
        for (int i = 0; i < adjlist[root].size(); i++) {
            if (currvisit[adjlist[root][i]]) {
                checkcycle = true;
                return;
            }
            if (visited[adjlist[root][i]] == false) {
                dfstopo(adjlist[root][i], adjlist, visited, currvisit, st);
            }
        }
        st.push(root);
        currvisit[root] = false;
    }
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjlist;
        for (int i = 0; i < prerequisites.size(); i++) {
            adjlist[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        stack<int> st;
        vector<bool> visited(V, false);
        vector<bool> currvisit(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfstopo(i, adjlist, visited, currvisit, st);
            }
        }
        if (checkcycle == true)
            return {};
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};