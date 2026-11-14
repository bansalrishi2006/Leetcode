class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyBefore(0);
        ListNode dummyAfter(0);
        
        ListNode* before = &dummyBefore;
        ListNode* after = &dummyAfter;
        
        while (head != nullptr) {
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        after->next = nullptr;
        before->next = dummyAfter.next;
        
        return dummyBefore.next;
    }
};
