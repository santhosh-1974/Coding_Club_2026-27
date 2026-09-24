class Solution {
public:
    //this recurison represents recursion code for subsequence
    int helper(vector<int>&nums1,vector<int>&nums2,int &n,int &m,int i,int j){
        if(i==n || j==m)return 0;
        if(nums1[i]==nums2[j])return 1+helper(nums1,nums2,n,m,i+1,j+1);
        return max(helper(nums1,nums2,n,m,i+1,j),helper(nums1,nums2,n,m,i,j+1));
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        //return helper(nums1,nums2,n,m,0,0);
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(nums1[i]==nums2[j])dp[i][j]=1+dp[i+1][j+1];
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};