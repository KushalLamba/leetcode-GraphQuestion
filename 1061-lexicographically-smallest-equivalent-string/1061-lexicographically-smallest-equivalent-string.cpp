class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x], parent);
    }
    void unionf(int x, int y, vector<int>& parent) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if(x_parent!=y_parent){
        if (x_parent > y_parent)
            parent[x_parent] = y_parent;
        else
            parent[y_parent] = x_parent;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        for (int i = 0; i < s1.length(); i++) {
            int x_parent = find(s1[i] - 'a', parent);
            int y_parent = find(s2[i] - 'a', parent);
            if (x_parent != y_parent)
                unionf(x_parent, y_parent, parent);
        }
        for (int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = find(baseStr[i]-'a', parent)+'a';
        }
        return baseStr;
    }
};