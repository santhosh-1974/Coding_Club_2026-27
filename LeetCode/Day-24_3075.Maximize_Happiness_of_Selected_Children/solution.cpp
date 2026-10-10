class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int c = 0;
        long long ans = 0;

        for (int& i : happiness) {
            ans += max(i - c, 0);
            c++;
            k--;
            if (k == 0) break;
        }

        return ans;
    }
};
