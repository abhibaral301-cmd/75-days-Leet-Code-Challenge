class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pres;
        for (int i = 0; i <= rowIndex; i++) {
            vector<int> curr(i + 1, 1);
            for (int j = 1; j < i; j++)
                curr[j] = pres[j] + pres[j - 1];
            pres = curr;
        }
        return pres;
    }
};