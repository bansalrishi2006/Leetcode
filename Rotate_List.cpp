class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        ListNode* current = head;
        int n = 1;
        while (current->next) {
            current = current->next;
            n++;
        }
        
        current->next = head;
        
        k = k % n;
        int stepsToNewHead = n - k;
        
        ListNode* newTail = current;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
