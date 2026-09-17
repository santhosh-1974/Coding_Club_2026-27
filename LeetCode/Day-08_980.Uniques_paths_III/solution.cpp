class Solution {
public:
    vector<int>rd={-1,0,1,0};
    vector<int>cd={0,-1,0,1};
    bool isValid(int r,int c,int m,int n){
        return r>=0 && c>=0 && r<m && c<n;
    }
    int DFS(vector<vector<int>>&grid,vector<vector<bool>>&vis,int r,int c,int &m,int &n){
        int count=0;
        vis[r][c]=1;
        if(grid[r][c]==2){
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]!=-1 && vis[i][j]==0){
                        vis[r][c]=0;
                        return 0;
                    }
                }
            }
            vis[r][c]=0;
            return 1;
        }
        for(int k=0;k<4;k++){
            int nr=r+rd[k];
            int nc=c+cd[k];
            if(isValid(nr,nc,m,n) && !vis[nr][nc] && grid[nr][nc]!=-1){
                count+=DFS(grid,vis,nr,nc,m,n);
            }
        }
        vis[r][c]=0;
        return count;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   return DFS(grid,vis,i,j,m,n);
                }
            }
        }
        return 0;
    }
};