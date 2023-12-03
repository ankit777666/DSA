class Solution
{
public:
    void inorder(Node* root, vector<int>&v) {
        if(root==NULL) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        int ans = 0;
        vector<int> v1, v2;
        inorder(root1, v1);
        inorder(root2, v2);
        
        int i=0; int j=v2.size()-1;
        
        while(i<v1.size() && j>=0) {
            int sum = v1[i]+v2[j];
            if(sum>x) j--;
            else if(sum<x) i++;
            else {
                ans++;
                i++;
                j--;
            }
        }
        return ans;
    }
};