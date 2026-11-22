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
    int findLength(ListNode* head){
        int size=0;
        while(head!=nullptr){
            size++;
            head=head->next;
        }
        return size;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;
        int sizeA = findLength(headA);
        int sizeB = findLength(headB);
        if(sizeA > sizeB){
            int diff=sizeA-sizeB;
            while(diff!=0){
                headA=headA->next;
                diff--;
            }
        }
        if(sizeA < sizeB){
            int diff=sizeB-sizeA;
            while(diff!=0){
                headB=headB->next;
                diff--;
            }
        }
        while(headA!=nullptr && headB!=nullptr){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};

//TC -> O(n+m) , SC -> O(1)