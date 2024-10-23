class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if (startGene == endGene)
            return 0;
        unordered_map<string, bool> bankfinder;
        string value = "ACTG";
        for (int i = 0; i < bank.size(); i++) {
            bankfinder[bank[i]] = false;
        }
        int level = 0;
        queue<string> pendingnodes;
        pendingnodes.push(startGene);
        while (!pendingnodes.empty()) {
            int size1 = pendingnodes.size();
            for (int p = 0; p < size1; p++) {
                string front = pendingnodes.front();
                pendingnodes.pop();
                if (front == endGene) return level;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 8; j++) {
                        string neighbour = front;
                        neighbour[j] = value[i];
                        if (bankfinder.find(neighbour) != bankfinder.end() &&
                            !bankfinder[neighbour]) {
                            pendingnodes.push(neighbour);
                            bankfinder[neighbour] = true;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};