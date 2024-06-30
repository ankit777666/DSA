void constructTree(vector<int>&v, int index, TreeNode* &node) {
    node = new TreeNode(v[index]);
    int left= 2*index+1, right = 2*index+2;
    
    if(left<v.size()) {
        constructTree(v, left, node->left);
    }
    else {
        return;
    }
    if(right<v.size()) {
        constructTree(v, right, node->right);
    }
    
}
void convert(Node *head, TreeNode *&root) {
    // Your code here
    vector<int>v;
    Node* temp = head;
    while(temp!=NULL) {
        v.push_back(temp->data);
        temp=temp->next;
    }
    constructTree(v, 0, root);
}