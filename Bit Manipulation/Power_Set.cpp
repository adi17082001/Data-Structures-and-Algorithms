class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;

        int noOfSubsets = (1 << n);
        for(int num = 0; num <= noOfSubsets - 1; num++){
            vector<int>list;
            for(int i = 0; i < n; i++){
                if(num & (1 << i)){
                    list.push_back(nums[i]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};
