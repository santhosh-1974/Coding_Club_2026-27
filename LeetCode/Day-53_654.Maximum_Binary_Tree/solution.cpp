/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int find_max(vector<int>&nums,int st,int end){
        int max=st;
        for(int i=st;i<=end;i++){
            if(nums[i]>nums[max])max=i;
        }
        return max;
    }
    TreeNode* construct(vector<int>&nums,int st,int end){
        if(st>end)return nullptr;
        int index=find_max(nums,st,end);
        TreeNode*root=new TreeNode(nums[index]);
        root->right=construct(nums,index+1,end);
        root->left=construct(nums,st,index-1);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums,0,nums.size()-1);
    }
};
