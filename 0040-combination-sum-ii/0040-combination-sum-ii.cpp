class Solution {
private:

    void backtrack(int start, int sum, int target,
                   vector<int>& candidates,
                   vector<int>& temp,
                   vector<vector<int>>& ans) {

        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            temp.push_back(candidates[i]);
            backtrack(i + 1,
                      sum + candidates[i],
                      target,
                      candidates,
                      temp,
                      ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        vector<vector<int>> ans;

        backtrack(0, 0, target, candidates, temp, ans);

        return ans;
    }
};