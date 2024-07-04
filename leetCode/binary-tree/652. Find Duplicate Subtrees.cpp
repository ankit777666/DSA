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
    string util(TreeNode* root, unordered_map<string, int>&umap, vector<TreeNode*>&duplicates) {
        if(!root)
            return "*";
        string left=util(root->left, umap,duplicates);
        string right=util(root->right, umap, duplicates);

        string s=left+','+right+','+to_string(root->val);
        if(umap[s]==1)
            duplicates.push_back(root);
        umap[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>umap;
        vector<TreeNode*>duplicates;

        util(root,umap, duplicates);
        return duplicates;
    }
};