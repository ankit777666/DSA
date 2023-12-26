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
    void util(TreeNode* root, string temp, vector<string>&ans) {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            // temp.push_back(char(root->val));
            temp+=to_string(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp+=to_string(root->val)+"->";
        
        util(root->left, temp, ans);
        util(root->right, temp, ans);
        //temp.pop_back();temp.pop_back();temp.pop_back();
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp="";
        util(root, temp, ans);
        return ans;
    }
};