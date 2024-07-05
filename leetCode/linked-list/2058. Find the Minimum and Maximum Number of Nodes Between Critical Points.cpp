/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head== NULL || head->next == NULL || head->next->next ==NULL)
            return {-1,-1};
        int count=0, mini=INT_MAX, maxi=INT_MIN;
        vector<int>v;
        ListNode* curr=head->next;
        ListNode* prev=head;
        ListNode* next=NULL;

        while(curr->next != NULL) {
            next=curr->next;
            if((curr->val<prev->val && curr->val<next->val) || (curr->val>prev->val and curr->val>next->val)) {
                v.push_back(count);
            }
            count++;
            prev=curr;
            curr=curr->next;
        }
        if(v.size()<=1)
            return {-1, -1};
        for(int i=1; i<v.size(); i++)
            mini=min(mini, v[i]-v[i-1]);
        maxi=v[v.size()-1]-v[0];

        return {mini, maxi};
    }
};