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
                ListNode* current=head;
                int ans=0;
                while(current!=NULL){
                        ans++;
                        current=current->next;
                }
                return ans;
        }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N=getLength(head);
            int k=N-n;
            if(k==0){
                    return head->next;
            }
            ListNode *prev=NULL, *current=head;
            while(k--){
                    prev=current;
                    current=current->next;
            }
            prev->next=current->next;
            return head;
    }
};