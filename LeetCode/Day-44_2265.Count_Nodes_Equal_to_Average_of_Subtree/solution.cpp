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
    pair<int,int> traverse(TreeNode* root,int &n){
        if(!root)return {0,0};
        auto ls=traverse(root->left,n);
        auto rs=traverse(root->right,n);
        int avg=(ls.first+rs.first+root->val)/(ls.second+rs.second+1);
        if(avg==root->val)n++;
        return {ls.first+rs.first+root->val,ls.second+rs.second+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int n=0;
        traverse(root,n);
        return n;
    }
};
