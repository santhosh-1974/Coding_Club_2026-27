class Solution {
public:
    bool helper(vector<int>&nums,int k,vector<bool>&used,int &target,int sum,int index){
        if(sum==target){
            return helper(nums,k-1,used,target,0,0);
        }
        if(k==1)return true;
        for(int i=index;i<nums.size();i++){
            if(used[i] || sum+nums[i]>target)continue;
            used[i]=1;
            if(helper(nums,k,used,target,sum+nums[i],i+1))return true;
            used[i]=0;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0)return false;
        int target=sum/k;
        vector<bool>used(nums.size(),false);
        return helper(nums,k,used,target,0,0);
    }
};