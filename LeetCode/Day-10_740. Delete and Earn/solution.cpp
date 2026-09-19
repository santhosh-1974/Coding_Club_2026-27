class Solution {
public:
    int helper(vector<int>&val,unordered_map<int,int>&m,int i){
        if(i==val.size())return 0;

        int next=i+1;
        while(next<val.size() && val[next]==val[i]+1)next++;
        int pick=m[val[i]]*val[i]+helper(val,m,next);

        int not_pick=helper(val,m,i+1);

        return max(pick,not_pick);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int &x:nums)m[x]++;

        vector<int>val;
        for(auto &[x,f]:m)val.push_back(x);

        sort(val.begin(),val.end());

        // return helper(val,m,0);

        vector<int>dp(val.size()+1,0);
        for(int i=val.size()-1;i>=0;i--){

            int next=i+1;
            while(next<val.size() && val[next]==val[i]+1)next++;
            int pick=m[val[i]]*val[i]+dp[next];

            int not_pick=dp[i+1];
            dp[i]=max(pick,not_pick);
        }
        return dp[0];
    }
};