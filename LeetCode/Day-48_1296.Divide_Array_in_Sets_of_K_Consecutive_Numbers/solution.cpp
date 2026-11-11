class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>m;
        for(int &i:nums)m[i]++;    
        while(true){
            int c=k;
            int prev=-1;
            for(auto &it:m){
                if(prev!=-1 && it.first!=prev+1)return false;
                it.second--;
                prev=it.first;
                if(!it.second)m.erase(it.first);
                c--;
                if(c==0)break;
            }
            if(m.size()==0){
                if(c!=0)return false;
                else break;
            }
        }
        return true;
    }
};
