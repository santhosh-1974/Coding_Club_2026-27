class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        unordered_map<char, pair<int, int>> mp = {
            {'R', {0, 1}},
            {'D', {1, 0}},
            {'L', {0, -1}},
            {'U', {-1, 0}},
        };
        int n = grid.size(), m = grid[0].size(), r, c;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        auto limatecega = grid;
        stack<pair<int, int>> st;

        st.push({0, 0});
        vis[0][0] = true;
        while (!st.empty()) {
            r = st.top().first;
            c = st.top().second;
            char ch = limatecega[r][c];
            st.pop();
            int nr = r + mp[ch].first;
            int nc = c + mp[ch].second;
            if (nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                st.push({nr, nc});
                vis[nr][nc] = true;
            }
        }
        return {r, c};
    }
};
