class Solution {
public:
    bool helper(vector<int>&nums,vector<bool>&used,int target,int k,int index,int sum){
        if(sum==target)return helper(nums,used,target,k-1,0,0);
        if(k==1)return true;
        for(int i=index;i<nums.size();i++){
            if(used[i] || sum+nums[i]>target)continue;
            used[i]=1;
            if(helper(nums,used,target,k,i+1,sum+nums[i]))return true;
            used[i]=0;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        int target=sum/4;
        if(sum%4!=0)return false;
        sort(matchsticks.rbegin(),matchsticks.rend());
        vector<bool>used(matchsticks.size(),false);
        return helper(matchsticks,used,target,4,0,0);
    }
};
