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
        ListNode *current=head, *aage=head->next;
        int sum=0;
            while(aage!=NULL){
                    if(aage->val==0){
                            current=current->next;
                            current->val=sum;
                            sum=0;
                    }
                    else{
                            sum+=aage->val;
                    }
                     aage=aage->next;
            }
            current->next=NULL;
            return head->next;
    }
};