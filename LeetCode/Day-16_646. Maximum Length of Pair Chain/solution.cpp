class Solution {
public:
    int helper(vector<vector<int>>&pairs,int i,int prev){
        if(i==pairs.size())return 0;
        int pick=0;
        if(prev==-1 || pairs[prev][1]<pairs[i][0])pick=1+helper(pairs,i+1,i);
        int not_pick=helper(pairs,i+1,prev);
        return max(pick,not_pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        // return helper(pairs,0,-1);
        int n=pairs.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            vector<int>temp(n+1,0);
            for(int prev=-1;prev<i;prev++){
                int pick=0;
                if(prev==-1 || pairs[prev][1]<pairs[i][0])pick=1+dp[i+1];
                int not_pick=dp[prev+1];
                temp[prev+1]=max(pick,not_pick);
            }
            dp=temp;
        }
        return dp[0];
    }
};