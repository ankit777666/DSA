class Solution{
  public:
    
    bool isDeadEndUtil(Node *root, int minVal, int maxVal) {
        if(root == NULL)
            return false;
        if(minVal == maxVal)
            return true;
        return isDeadEndUtil(root->left, minVal, root->data-1) || isDeadEndUtil(root->right, root->data+1, maxVal);
    }
    
    bool isDeadEnd(Node *root)
    {
        //Your code here
        int minVal = 1;
        int maxVal = INT_MAX;
        return isDeadEndUtil(root, minVal, maxVal);
    }
};