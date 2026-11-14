class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;

        for (int i = l; i <= r; i++) {
            for (int j = 0; j <= nums.size() - i; j++) {
                int temp = 0;

                for (int k = j; k < j + i; k++) {
                    temp += nums[k];
                }

                if (temp > 0) {
                    mini = min(temp, mini);
                }
            }
        }

        if (mini == INT_MAX)
            return -1;

        return mini;
    }
};