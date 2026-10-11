class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        ans = nums[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                ans = nums[i] = nums[i - 1] + 1;
            }
        }

        return ans;
    }
};
