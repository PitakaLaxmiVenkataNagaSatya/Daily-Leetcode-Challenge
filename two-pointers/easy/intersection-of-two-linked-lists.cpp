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

    bool isIntersection(ListNode* headA, ListNode* node){
        while(headA!=nullptr){
            if(headA==node) return true;
            headA = headA->next;
        }
        return false;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return nullptr;
        while(headB!=nullptr){
            if(isIntersection(headA, headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

//TC -> O(m*n) , SC -> O(1)