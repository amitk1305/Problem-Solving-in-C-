class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }
};