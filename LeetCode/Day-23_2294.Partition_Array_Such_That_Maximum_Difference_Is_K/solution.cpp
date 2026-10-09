class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int c = 0, l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - nums[l] > k) {
                c++;
                l = i;
            }
        }
        return c + 1;
    }
};
