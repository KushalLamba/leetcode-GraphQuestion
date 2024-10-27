class Solution {
public:
    int possibleStringCount(string word) {
        int size1=word.size();
        if(size1==1) return 1;
        int count=0;
        for(int i=1;i<word.size();i++)
        {
            if(word[i]==word[i-1]) count++;
        }
        return count+1;
    }
};