class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<int> rd = {0, -1, -1, -1, 0, 1, 1, 1};
        vector<int> cd = {-1, -1, 0, 1, 1, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int alive = 0;
                for (int k = 0; k < 8; k++) {
                    int nr = i + rd[k];
                    int nc = j + cd[k];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                        (board[nr][nc] == 1 || board[nr][nc] == -1)) {
                        alive++;
                    }
                }
                if (board[i][j] == 1 && (alive < 2 || alive > 3)) {
                    board[i][j] = -1;
                } else if (!board[i][j] && alive == 3) {
                    board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
};
