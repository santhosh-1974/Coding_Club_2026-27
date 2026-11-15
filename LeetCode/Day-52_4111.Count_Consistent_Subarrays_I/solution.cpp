class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int curr=0,mini=INT_MAX,val=nums[i];
            for(int j=i;j<nums.size();j++){
                if(nums[j]<mini)mini=nums[j];
                val&=nums[j];
                if(mini==val)ans++;
            }
        }
        return ans;
    }
};
