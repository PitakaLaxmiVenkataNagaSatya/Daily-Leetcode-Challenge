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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if(list1==NULL) return list2;
        // if(list2==NULL) return list1;
        // if(list1->val<=list2->val){
        //     ListNode* ansNode=mergeTwoLists(list1->next, list2);
        //     list1->next=ansNode;
        //     return list1;
        // }
        // else{
        //     ListNode* ansNode=mergeTwoLists(list1, list2->next);
        //     list2->next=ansNode;
        //     return list2;
        // } 

        //ITERATIVE SOLUTION
        // if(list1==NULL) return list2;
        // if(list2==NULL) return list1;
        // ListNode* head = (list1->val <= list2->val) ? list1 : list2;
        // ListNode* l1=list1;
        // ListNode* l2=list2;
        // ListNode* prev=NULL;
        // while(l1!=NULL && l2!=NULL){
        //     if(l1->val<=l2->val){
        //         ListNode* newNode=l1->next;
        //         l1->next=l2;
        //         if(prev!=NULL){
        //             prev->next=l1;
        //         }
        //         prev=l1;
        //         l1=newNode;
        //     }
        //     else{
        //         ListNode* newNode=l2->next;
        //         l2->next=l1;
        //         if(prev!=NULL){
        //             prev->next=l2;
        //         }
        //         prev=l2;
        //         l2=newNode;
        //     }
        // } 
        // return head;  

        // DUMMY NODE ITERATIVE METHOD
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        tail->next = (list1!=NULL) ? list1 : list2;
        return dummy.next;    
    }
};