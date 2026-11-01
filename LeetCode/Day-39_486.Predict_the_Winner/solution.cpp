class Solution {
public:
    int play(vector<int>&nums,int st,int end,bool isPlayer){
        if(st>end)return 0;
        if(isPlayer){
            int c1=play(nums,st+1,end,!isPlayer)+nums[st];
            int c2=play(nums,st,end-1,!isPlayer)+nums[end];
            return max(c1,c2);
        }
        int c1=play(nums,st+1,end,!isPlayer)-nums[st];
        int c2=play(nums,st,end-1,!isPlayer)-nums[end];
        return min(c1,c2);
    }
    bool predictTheWinner(vector<int>& nums){
        int c1=0,c2=0,n=nums.size();
        //return play(nums,0,n-1,true) >= 0;
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n;i>=1;i--){
            vector<vector<int>>temp(n+1,vector<int>(2,0));
            temp[i][0]=-nums[i-1];
            temp[i][1]=nums[i-1];
            for(int j=i+1;j<=n;j++){
                temp[j][0]=min(dp[j][1]-nums[i-1],temp[j-1][1]-nums[j-1]);
                temp[j][1]=max(dp[j][0]+nums[i-1],temp[j-1][0]+nums[j-1]);
            }
            dp=temp;
        }
        return dp[n][1]>=0;
    }
};
