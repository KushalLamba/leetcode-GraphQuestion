class Solution {
public:
    int binarysearch(int start, int end, vector<int>& nums, int target) {
        if (start > end)
            return -1;
        int mid = (start + end) / 2;
        if (nums[mid] == target)
            return mid;
        if (target < nums[mid])
            return binarysearch(start, mid - 1, nums, target);
        return binarysearch(mid + 1, end, nums, target);
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = nums.size()-1;
        for (int i = 1; i < n ; i++) {
            if (nums[i-1] > nums[i]) {
                k = i;
                break;
            }
            if(nums[i]==target) return true;
        }

        if (nums[0] <= target) {
            return binarysearch(0, k, nums, target) != -1;
        }
        return binarysearch(k, n - 1, nums, target) != -1;
    }
};