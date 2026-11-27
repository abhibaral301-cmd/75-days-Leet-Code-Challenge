class Solution {
public:
    unordered_set<int> col, posDiag, negDiag;
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return res;
    }

    void backtrack(int r, int n, vector<string>& board){
        if(r == n){
            res.push_back(board);
            return;
        }

        for(int c=0; c<n; c++){
            if(col.count(c) || posDiag.count(r+c) || negDiag.count(r-c)){
                continue;
            }
            col.insert(c);
            posDiag.insert(r+c);
            negDiag.insert(r-c);
            board[r][c] = 'Q';

            backtrack(r+1, n, board);

            col.erase(c);
            posDiag.erase(r+c);
            negDiag.erase(r-c);
            board[r][c] = '.';
        }
    }
};