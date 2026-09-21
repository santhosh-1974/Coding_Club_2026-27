class Solution {
public:
    int helper(string &s,int index){
        if(index==s.size())return 1;
        if(s[index]=='0')return 0;
        int ans=0;
        for(int i=index;i<s.size();i++){
            if(i-index+1>2)break;
            int num=stoi(s.substr(index,i-index+1));
            if(num>=1 && num<=26){
                ans+=helper(s,i+1);
            }
        }
        return ans;
    }
    int numDecodings(string s) {
        // return helper(s,0);
        vector<int>dp(s.size()+1,0);
        dp[s.size()]=1;
        for(int index=s.size()-1;index>=0;index--){
            if(s[index]=='0')continue;
            int ans=0;
            for(int i=index;i<s.size();i++){
                if(i-index+1>2)break; 
                int num=stoi(s.substr(index,i-index+1));
                if(num>=1 && num<=26){
                    ans+=dp[i+1];
                }
            }
            dp[index]=ans;
        }
        return dp[0];
    }
};