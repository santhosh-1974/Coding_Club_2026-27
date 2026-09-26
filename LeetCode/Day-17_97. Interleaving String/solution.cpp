class Solution {
public:
    bool helper(string s1,string s2,string s3,int i,int j,int k){
        if(i==s1.size() && j==s2.size() && k==s3.size())return true;
        if(i==s1.size())return s2[j]==s3[k] && helper(s1,s2,s3,i,j+1,k+1);
        if(j==s2.size())return s1[i]==s3[k] && helper(s1,s2,s3,i+1,j,k+1);
        if(s1[i]==s2[j] && s2[j]==s3[k]){
            return helper(s1,s2,s3,i+1,j,k+1) || helper(s1,s2,s3,i,j+1,k+1);
        }
        if(s1[i]==s3[k])return helper(s1,s2,s3,i+1,j,k+1);
        else if(s2[j]==s3[k])return helper(s1,s2,s3,i,j+1,k+1);
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        int n=s1.size(),m=s2.size();
        // return helper(s1,s2,s3,0,0,0);
        vector<vector<int>>dp(n+1,vector<int>(m+1,false));
        dp[n][m]=1;
        for(int k=s3.size()-1;k>=0;k--){
            vector<vector<int>>temp(n+1,vector<int>(m+1,false));
            temp[n][m]=1;
            for(int j=0;j<m;j++)temp[n][j]=(s2[j]==s3[k]) && dp[n][j+1];
            for(int i=0;i<n;i++)temp[i][m]=(s1[i]==s3[k]) && dp[i+1][m];
            for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    
                    if(s1[i]==s2[j] && s2[j]==s3[k]){
                        temp[i][j]=dp[i+1][j] || dp[i][j+1];
                    }
                    else if(s1[i]==s3[k])temp[i][j]=dp[i+1][j];
                    else if(s2[j]==s3[k])temp[i][j]=dp[i][j+1];
                    else temp[i][j]=false;
                }
            }
            dp=temp;
        }
        return dp[0][0];
    }
};