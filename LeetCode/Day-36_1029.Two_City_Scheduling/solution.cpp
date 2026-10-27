class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](const vector<int>&a,const vector<int>&b){
            return (a[0]-a[1]) < (b[0]-b[1]);
        });
        int l=0,r=costs.size()-1,sum=0;
        while(l<r){
            sum+=costs[l++][0]+costs[r--][1];
        }
        return sum;
    }
};
