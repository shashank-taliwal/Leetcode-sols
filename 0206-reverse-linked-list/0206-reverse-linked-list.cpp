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
    ListNode* reverseList(ListNode* head) {
            if(!head or !head->next)return head;
            ListNode *prevPtr=NULL, *curr=head, *nextPtr=head->next;
            while(nextPtr){
                    curr->next=prevPtr;
                    // nextPtr->next=curr;
                    prevPtr=curr;
                    curr=nextPtr;
                    nextPtr=nextPtr->next;
            }
            curr->next=prevPtr;
            head=curr;
            return head;
    }
};