/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
            if(!head or !head->next)return false;
            do{
                    slow=slow->next;
                    fast=fast->next->next;
            }while(slow!=fast and fast and fast->next);
            return slow==fast;
    }
};