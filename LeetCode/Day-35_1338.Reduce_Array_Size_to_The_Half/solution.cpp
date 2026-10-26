class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i : arr) {
            m[i]++;
        }

        vector<vector<int>> v;
        for (auto it : m) {
            v.push_back({it.first, it.second});
        }

        sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int n = arr.size(), half = n / 2, ans = 0;
        for (auto vec : v) {
            ans++;
            n -= vec[1];
            if (n <= half) break;
        }

        return ans;
    }
};
