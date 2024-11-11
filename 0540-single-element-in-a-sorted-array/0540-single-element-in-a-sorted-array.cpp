class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int x=-1;
        while(start<end)
        {
            int mid=(start+end)/2;
            if(mid-1>=0 && nums[mid]==nums[mid-1])
            {
                if((mid-start-1)%2!=0)
                {
                    end=mid-2;
                }
                else start=mid+1;
            }
            else if(mid+1<nums.size() && nums[mid]==nums[mid+1])
            {
                if((end-mid-1)%2!=0)
                {
                    start=mid+2;
                }
                else end=mid-1;
            }
            else{
                x=nums[mid];
                break;
            }
        }
        if(x==-1) return nums[start];
        return x;
    }
};