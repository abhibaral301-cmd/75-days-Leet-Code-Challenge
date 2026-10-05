class Solution {
public:
    vector<int> row;
    vector<int> col;
    vector<int> box;

    bool solve(vector<vector<char>>& board) {
        int best = 10;
        int r = -1;
        int cl = -1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int used = row[i] | col[j] | box[3 * (i / 3) + (j / 3)];
                    int cnt = 9 - __builtin_popcount(used);
                    if (cnt == 0) {
                        return false;
                    }
                    if (cnt < best) {
                        best = cnt;
                        r = i;
                        cl = j;
                    }
                    if (best == 1) {
                        break;
                    }
                }
                if (best == 1) {
                    break;
                }
            }
        }
        if (r == -1) {
            return true;
        }
        int used = row[r] | col[cl] | box[(3 * (r / 3)) + (cl / 3)];
        for (int k = 0; k < 9; k++) {
            int bit = (1 << k);
            if (used & bit) {
                continue;
            }
            board[r][cl] = k + '1';
            row[r] |= bit;
            col[cl] |= bit;
            box[3 * (r / 3) + (cl / 3)] |= bit;
            if (solve(board)) {
                return true;
            }
            board[r][cl] = '.';
            row[r] &= ~bit;
            col[cl] &= ~bit;
            box[3 * (r / 3) + (cl / 3)] &= ~bit;
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        row.assign(9, 0);
        col.assign(9, 0);
        box.assign(9, 0);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int bit = (1 << (board[i][j] - '1'));
                    row[i] |= bit;
                    col[j] |= bit;
                    box[3 * (i / 3) + (j / 3)] |= bit;
                }
            }
        }
        solve(board);
    }
};