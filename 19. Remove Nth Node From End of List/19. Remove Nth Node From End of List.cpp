//Author: Devendra Uraon 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1 = head;
        while(n-- && ptr1)
            ptr1 = ptr1 -> next;
        ListNode* ptr2 = head;
        if(ptr1 != NULL){
            while(ptr1 -> next){
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
            ptr2 -> next = ptr2 -> next -> next;
        }
        else head = head -> next;
        return head;
    }
};
