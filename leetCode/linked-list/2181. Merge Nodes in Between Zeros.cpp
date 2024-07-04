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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newHead=head->next;
        ListNode* curr=newHead;
        while(curr!=NULL) {
            int sum=0;
            while(curr->val !=0) {
                sum+=curr->val;
                curr=curr->next;
            }
            newHead->val=sum;
            curr=curr->next;
            newHead->next=curr;
            newHead=newHead->next;
        }
        return head->next;
    }
};