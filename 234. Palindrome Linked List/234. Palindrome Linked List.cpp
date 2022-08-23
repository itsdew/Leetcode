//Author: Devendra Uraon
class Solution {
public:
    ListNode* reverse(ListNode* slow){
        ListNode* dummy = NULL;
        while(slow!=NULL){
            ListNode* next = slow->next;
            slow->next = dummy;
            dummy = slow;
            slow = next;
        }
        return dummy;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast=head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow;
        slow->next = reverse(slow->next);
        slow = slow->next;
        while(slow!=NULL){
            if(head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};