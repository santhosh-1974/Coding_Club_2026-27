class Solution {
public:
    vector<int> rd = {-1, 0, 1, 0}, cd = {0, -1, 0, 1};

    bool DFS(vector<vector<char>>& board, string word,
             vector<vector<bool>>& vis, int& n, int& m,
             int r, int c, int k) {
        if (k == word.size()) return true;

        for (int i = 0; i < 4; i++) {
            int nr = r + rd[i];
            int nc = c + cd[i];
            if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                !vis[nr][nc] && board[nr][nc] == word[k]) {
                vis[nr][nc] = true;
                if (DFS(board, word, vis, n, m, nr, nc, k + 1)) return true;
                vis[nr][nc] = false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<bool>> vis(n, vector<bool>(m, false));
                vis[i][j] = true;
                if (board[i][j] == word[0] && DFS(board, word, vis, n, m, i, j, 1)) {
                    return true;
                }
            }
        }

        return false;
    }
};
