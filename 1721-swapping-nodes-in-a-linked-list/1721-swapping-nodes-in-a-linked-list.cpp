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
        int getLength(ListNode* head){
                ListNode* ptr=head;
                int ans=0;
                while(ptr){
                        ans++;
                        ptr=ptr->next;
                }
                return ans;
        }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n=getLength(head);
        int fromBeginning=k;
        int fromEnd=n-k;
        ListNode *front=head, *back=head;
        while(fromBeginning-1 or fromEnd){
                if(fromBeginning-1){
                        front=front->next;
                        fromBeginning--;
                }
                if(fromEnd){
                        back=back->next;
                        fromEnd--;
                }
        }
            swap(front->val,back->val);
            return head;
            
    }
};