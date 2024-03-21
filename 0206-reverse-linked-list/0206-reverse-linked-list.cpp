class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur = head, *forward;
        
        while(cur != NULL){
            forward = cur->next;
            cur->next = prev;
            prev = cur;
            cur = forward;
        }
        
        return prev;
    }
};