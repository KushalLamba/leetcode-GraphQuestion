class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int bit = 1 << i;
            int one = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] & bit) != 0)
                    one++;
            }
            if (one % 3 != 0)
                ans = ans | bit;
        }
        return ans;
    }
};