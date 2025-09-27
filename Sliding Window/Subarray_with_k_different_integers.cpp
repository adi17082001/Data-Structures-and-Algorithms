class Solution {
public:
    int func(vector<int>&nums, int k){
        int l = 0, r = 0, ct = 0;
        unordered_map<int, int> mpp;
        int n = nums.size();
        while (r < n) {
            mpp[nums[r]]++;

            // Shrink the window if there are more than 'k' distinct elements
            while (mpp.size() > k) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }

            // Count the subarrays with at most k distinct elements
            ct =  ct + (r - l + 1); // Add the number of subarrays ending at 'r'
            r++;
        }
        return ct;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};
