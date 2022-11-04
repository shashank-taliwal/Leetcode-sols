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
        int value(ListNode* temp){
                if(temp==NULL)return 0;
                return temp->val;
        }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
            ListNode* res, *resHead;
            res=new ListNode(0);
            resHead=res;
         ListNode *ptr1=l1,*ptr2=l2;
            while(l1!=NULL or l2!=NULL){
                    int sum=value(l1)+value(l2)+carry;
                    res->next=new ListNode(sum%10);
                    carry=sum/10;
                    res=res->next;
                    if(l1)l1=l1->next;
                    if(l2)l2=l2->next;
            }
            if(carry>0){
                    res->next=new ListNode(carry);
            }
            return resHead->next;
    }
};