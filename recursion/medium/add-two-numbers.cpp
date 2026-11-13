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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode(0);
        ListNode* a=temp;
        int carry=0;
        int x;
        while(l1!=NULL || l2!=NULL){
            ListNode* y=new ListNode(0);
            if(l1==NULL){
                x=l2->val+carry;
                if(x>9){
                    y->val=x%10;
                    carry=x/10;
                }
                
                else{
                    y->val=x;
                    carry=0;
                }
                l2=l2->next;
            }
            else if(l2==NULL){
                x=l1->val+carry;
                if(x>9){
                    y->val=x%10;
                    carry=x/10;
                }
                
                else{
                    y->val=x;
                    carry=0;
                }
                l1=l1->next;
            }
            else{
                x=l1->val+l2->val+carry;
                if(x>9){
                    y->val=x%10;
                    carry=x/10;
                }
                
                else{
                    y->val=x;
                    carry=0;
                }
                l1=l1->next;
                l2=l2->next;
            }
            a->next=y;
            a=y;
        }
        if(carry!=0){
            ListNode* y=new ListNode(carry);
            a->next=y;
        }
        return temp->next;
    }
};


