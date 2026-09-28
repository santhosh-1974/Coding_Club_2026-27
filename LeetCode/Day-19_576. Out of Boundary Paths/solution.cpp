class Solution {
public:
    vector<int>rd={-1,0,1,0},cd={0,-1,0,1};
    // int findPaths(int m, int n, int maxMove, int r, int c) {
    //     if(maxMove<0)return 0;
    //     if(r<0 || c<0 || r>=m || c>=n)return 1;
    //     int ans=0;
    //     for(int i=0;i<4;i++){
    //         int nr=r+rd[i];
    //         int nc=c+cd[i];
    //         ans+=findPaths(m,n,maxMove-1,nr,nc);
    //     }
    //     return ans;
    // }
    int findPaths(int m, int n, int k, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int maxMove=1;maxMove<=k;maxMove++){
            vector<vector<int>>temp(m,vector<int>(n,0));
            for(int r=0;r<m;r++){
                for(int c=0;c<n;c++){
                    int ans=0;
                    for(int i=0;i<4;i++){
                        int nr=r+rd[i];
                        int nc=c+cd[i];
                        if(nr<0 || nc<0 || nr>=m || nc>=n)temp[r][c]=(temp[r][c]+1)%MOD;
                        else temp[r][c]=(temp[r][c]+dp[nr][nc])%MOD;
                    }
                }
            }
            dp=temp;
        }
        return dp[startRow][startColumn];
    }
};