# File: LeetCode/Day-43_2780.Minimum_Index_of_a_Valid_Split/solution.cpp
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxi,freq=0;
        for(int i:nums){
            m[i]++;
            if(freq<m[i]){
                freq=m[i];
                maxi=i;
            }
        }
        vector<int>v(nums.size(),0);
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi)v[i]=++c;
        }
        for(int i=0;i<nums.size();i++){
            if(v[i]>(i+1)/2 && freq-v[i]>(nums.size()-i-1)/2)return i;
        }
        return -1;
    }
};
