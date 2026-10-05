class Solution {
public:
    int bound(vector<int>& nums, int target, bool upper) {
        int l = 0, r = nums.size();

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < target || 
                (upper && nums[mid] == target))
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // First occurrence
        int first = bound(nums, target, false);

        // Target doesn't exist
        if (first == nums.size() || nums[first] != target)
            return {-1, -1};

        // Last occurrence
        int last = bound(nums, target, true) - 1;

        return {first, last};
    }
};