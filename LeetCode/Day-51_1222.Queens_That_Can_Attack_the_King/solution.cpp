class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>ans;
        sort(queens.begin(),queens.end(),[&](const vector<int>&a,const vector<int>&b){
            return abs(a[0]-king[0])+abs(a[1]-king[1]) < abs(b[0]-king[0])+abs(b[1]-king[1]);
        });
        int n=queens.size();
        vector<bool>vis(8,false);
        for(auto &vec:queens){
            if(vec[0]==king[0]){
                if(vec[1]<king[1] && !vis[0]){
                    ans.push_back(vec);
                    vis[0]=1;
                }
                else if(vec[1]>king[1] && !vis[1]){
                    ans.push_back(vec);
                    vis[1]=1;
                }
            }
            if(vec[1]==king[1]){
                if(vec[0]<king[0] && !vis[2]){
                    ans.push_back(vec);
                    vis[2]=1;
                }
                else if(vec[0]>king[0] && !vis[3]){
                    ans.push_back(vec);
                    vis[3]=1;
                }
            }
            if(vec[0]+vec[1]==king[0]+king[1]){
                if(vec[0]<king[0] && !vis[4]){
                    ans.push_back(vec);
                    vis[4]=1;
                }
                else if(vec[0]>king[0] && !vis[5]){
                    ans.push_back(vec);
                    vis[5]=1;
                }
            }
            if(n-1+vec[1]-vec[0]==n-1+king[1]-king[0]){
                if(vec[0]<king[0] && !vis[6]){
                    ans.push_back(vec);
                    vis[6]=1;
                }
                else if(vec[0]>king[0] && !vis[7]){
                    ans.push_back(vec);
                    vis[7]=1;
                }
            }
        }
        return ans;
    }
};
