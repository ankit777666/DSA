/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


//Function to return a list containing the level order traversal in spiral form.
int findHeight(Node* root) {
    if (root == NULL)
        return 0;
    else {
 
    int lheight = findHeight(root->left);
    int rheight = findHeight(root->right);

    if (lheight > rheight)
        return (lheight + 1);
    else
        return (rheight + 1);
    }
}
void findSpiralUtil(Node* root,int level, vector<int>&ans, bool flag) {
    if(root==NULL) {
        return;
    }
    if(level==1)
        ans.push_back(root->data);
    else if(level>1) {
        if(flag) {
            findSpiralUtil(root->left, level-1, ans, flag);
            findSpiralUtil(root->right, level-1, ans, flag);
        }
        else {
            findSpiralUtil(root->right, level-1, ans, flag);
            findSpiralUtil(root->left, level-1, ans, flag);
        }
    }
}
vector<int> findSpiral(Node *root)
{
    //Your code here
    int h=findHeight(root);
    bool flag=false;
    vector<int>ans;
    for(int i=1; i<=h; i++) {
        findSpiralUtil(root, i, ans, flag);
        flag=!flag;
    }
    return ans;
    
    
}