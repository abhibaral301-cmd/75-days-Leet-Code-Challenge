class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n   = nums.size();
        int ans = 0;

        // 0 to n tak XOR karo
        for(int i=0; i<=n; i++){
            ans ^= i;
        }

        // array ke elements se XOR karo
        for(int i=0; i<n; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};