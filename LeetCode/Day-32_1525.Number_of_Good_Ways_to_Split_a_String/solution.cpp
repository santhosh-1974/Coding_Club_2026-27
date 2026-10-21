class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> m1(n, 0), m2(n, 0);
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(s[i]);
            m1[i] = st.size();
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            st.insert(s[i]);
            m2[i] = st.size();
        }
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (m1[i] == m2[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};
