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
    void inorderUtil(TreeNode* root, vector<int>&inorder) {
        if(root==NULL)  return;
        inorderUtil(root->left,inorder);
        inorder.push_back(root->val);
        inorderUtil(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inorderUtil(root,inorder);
        int low=0, high=inorder.size()-1;
        while(low<high) {
            int sum=inorder[low]+inorder[high];
            if(sum== k) return true;
            if(sum>k) high--;
            else    low++;
        }
        return false;
    }
};