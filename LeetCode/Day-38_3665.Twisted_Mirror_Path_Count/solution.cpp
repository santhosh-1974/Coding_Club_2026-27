class Solution {
public:
    const int MOD=1e9+7;
    vector<int>rd={1,0},cd={0,1};
    bool isValid(vector<vector<int>>&grid,int i,int j){
        return i>=0 && j>=0 && i<grid.size() && j<grid[0].size();
    }
    int helper(vector<vector<int>>&grid,int r,int c,bool fromLeft){
        if(r==grid.size()-1 && c==grid[0].size()-1)return 1;
        if(!isValid(grid,r,c))return 0;
        if(grid[r][c]==1){
            if(fromLeft)return helper(grid,r+1,c,false);
            else return helper(grid,r,c+1,true);
        }
        int count=0;
        for(int k=0;k<2;k++){
            int nr=r+rd[k];
            int nc=c+cd[k];
            count+=helper(grid,nr,nc,k);
        }
        return count;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        // return helper(grid,0,0,0);
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(2,0));
        dp[m-1][0]=dp[m-1][1]=1;
        for(int r=n-1;r>=0;r--){
            vector<vector<int>>temp(m+1,vector<int>(2,0));
            for(int c=m-1;c>=0;c--){
                if(r==n-1 && c==m-1){
                    temp[c][0]=temp[c][1]=1;
                    continue;
                }
                for(int fromLeft=0;fromLeft<=1;fromLeft++){
                    int count=0;
                    if(grid[r][c]==1){
                        if(fromLeft)temp[c][fromLeft]=dp[c][0];
                        else temp[c][fromLeft]=temp[c+1][1];
                    }
                    else{
                        temp[c][fromLeft]=(dp[c][0]+temp[c+1][1])%MOD;
                    }
                }
            }
            dp=temp;
        }
        return dp[0][0];
    }
};
