class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> set(deadends.begin(), deadends.end());
        if (set.find("0000") != set.end()) {
            return -1;
        }

        queue<pair<string, int>> pendingnodes;
        pendingnodes.push({"0000", 0});
        set.insert("0000");

        while (!pendingnodes.empty()) {
            string current = pendingnodes.front().first;
            int level = pendingnodes.front().second;
            pendingnodes.pop();

            if (current == target) {
                return level;
            }

            for (int i = 0; i < 4; i++) {
                for (int delta = -1; delta <= 1; delta += 2) {
                    string next = current;
                    next[i] = (next[i] - '0' + delta + 10) % 10 + '0';

                    if (set.find(next) == set.end()) {
                        set.insert(next);
                        pendingnodes.push({next, level + 1});
                    }
                }
            }
        }

        return -1;
    }
};