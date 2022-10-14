//Author: Devendra Uraon
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL) return head -> next;
        ListNode* slow = head, *fast = head, *prev = NULL;
        while(fast && fast -> next) {
            prev = slow;
        slow = slow -> next;
        fast = fast -> next->next;
    }
        prev -> next = slow -> next;
        return head;
    }
};
