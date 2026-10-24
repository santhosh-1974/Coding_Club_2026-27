class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        int st=0,end=nums.size()-1;
        for(int i=0;i<nums.size();i++)nums[i]=abs(nums[i]);
        sort(nums.begin(),nums.end());
        while(st<=end){
            if(st==end){
                ans+=(nums[st]*nums[st]);
                break;
            }
            ans+=(nums[end]*nums[end])-(nums[st]*nums[st]);
            st++;
            end--;
        }
        return ans;
    }
};
