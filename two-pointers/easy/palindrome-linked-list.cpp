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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        string s="";
        while(fast!=nullptr && fast->next!=nullptr){
            s += u_char(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=nullptr) slow=slow->next;
        for(int i=s.size()-1; i>=0; i--){
            if(slow==nullptr || u_int(s[i])!=slow->val) return false;
            slow=slow->next;
        }
        return true;
    }
};