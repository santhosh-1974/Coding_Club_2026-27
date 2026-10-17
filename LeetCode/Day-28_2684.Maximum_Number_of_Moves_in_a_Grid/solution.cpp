class Solution {
public:
    vector<int> rd = {-1, 0, 1}, cd = {1, 1, 1};
    // int DFS(vector<vector<int>>& grid, int r, int c, int n, int m) {
    //     int count = 0;
    //     for (int i = 0; i < 3; i++) {
    //         int nr = r + rd[i];
    //         int nc = c + cd[i];
    //         if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
    //             grid[nr][nc] > grid[r][c]) {
    //             count = max(DFS(grid, nr, nc, n, m) + 1, count);
    //         }
    //     }
    //     return count;
    // }
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int c = m - 2; c >= 0; c--) {
            for (int r = 0; r < n; r++) {
                for (int k = 0; k < 3; k++) {
                    int nr = r + rd[k];
                    int nc = c + cd[k];
                    if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                        grid[nr][nc] > grid[r][c]) {
                        dp[r][c] = max(dp[nr][nc] + 1, dp[r][c]);
                    }
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};
