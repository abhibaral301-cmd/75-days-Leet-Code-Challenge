class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> steps(size, INT_MAX);
        int max_reached = 0;

        steps[0] = 0;

        for(int i = 0; i<size; i++) {
            for(int z = max_reached; z < size && z <= i + nums[i]; z++) {
                steps[z] = min(steps[z], steps[i] + 1);
                max_reached = z;
            }
        }

        return steps.back();
    }
};