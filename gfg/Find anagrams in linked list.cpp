/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<Node*> ans;
        vector<int> v(26), temp(26);
        for(char ch : s) {
            v[ch-'a']++;
        }
        auto start=head, end=head;
        while(end) {
            char ch=end->data;
            temp[ch-'a']++;
            if(temp==v) {
                ans.push_back(start);
                start=end->next;
                end->next=nullptr;
                end=start;
                for(int i=0; i<26; i++) {
                    temp[i]=0;
                }
            }
            else {
                while(temp[ch-'a']>v[ch-'a']) {
                    temp[start->data-'a']--;
                    start=start->next;
                }
                end=end->next;
            }
        }
        return ans;
    }
};