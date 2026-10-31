class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        for(int i=0;i<num;i++){
            int val=min(9,sum);
            ans+=to_string(val);
            sum-=val;
        }
        if(sum)return "";
        return ans;
    }
};
