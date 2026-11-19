class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int t1 = nums[n - 1] - nums[2];
        int t2 = nums[n - 2] - nums[1];
        int t3 = nums[n - 3] - nums[0];
        
        return min({t1, t2, t3});
    }
};