class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int>m;
        for(int i:nums)m[i]++;
        vector<int>ans;
        while(1){
            bool canBreak=true;
            for(auto &it:m){
                if(it.second){
                    ans.push_back(it.first);
                    it.second--;
                    canBreak=false;
                }
            }
            if(canBreak)break;
        }
        return ans;
    }
};