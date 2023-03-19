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
    ListNode *detectCycle(ListNode *head) {
            ListNode *slow=head,*fast=head;
            if(!head or !head->next)return nullptr;
            do{
                    slow=slow->next;
                    fast=fast->next->next;
            }while(slow!=fast and fast and fast->next);
            
            if(slow==fast){
                    fast=head;
                    while(slow!=fast){
                            slow=slow->next;
                            fast=fast->next;
                    }
                    return slow;
            }
            return nullptr;
    }
};