class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        auto mini=min_element(nums.begin(),nums.end());
        auto maxi=max_element(nums.begin(),nums.end());

        int min_index=distance(nums.begin(),mini);
        int max_index=distance(nums.begin(),maxi);
        
        cout<<min_index<<" "<<max_index;
        int val1=0,val2=0,val3=0;
        if(min_index>max_index){
            swap(min_index,max_index);
        }

        val1+=min_index+1+nums.size()-max_index;
        val2=max_index+1;
        val3=nums.size()-min_index;

        return min(val1,min(val2,val3));
    }
};