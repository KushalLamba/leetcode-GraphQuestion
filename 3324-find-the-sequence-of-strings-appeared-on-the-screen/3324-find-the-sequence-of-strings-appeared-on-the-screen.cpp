class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string s="";
        for(int i=0;i<target.size();i++)
        {
            for(int j=0;j<26;j++)
            {
                char currentchar='a'+j;
                if(target[i]!=currentchar)
                {
                    if(s.empty()) ans.push_back(string(1,currentchar));
                    else ans.push_back(s+currentchar);
                }
                else
                {
                    ans.push_back(s+currentchar);
                    s.push_back(currentchar);
                    break;   
                }
            }
        }
        return ans;
    }
};