#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }
};

ListNode* createLinkedList(const std::initializer_list<int>& values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

void printLinkedList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) {
            std::cout << " -> ";
        }
        node = node->next;
    }
    std::cout << std::endl;
}

void freeLinkedList(ListNode* node) {
    while (node != nullptr) {
        ListNode* temp = node;
        node = node->next;
        delete temp;
    }
}

int main() {
    ListNode* l1 = createLinkedList({2, 4, 3});
    ListNode* l2 = createLinkedList({5, 6, 4});

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    std::cout << "Result: ";
    printLinkedList(result);

    freeLinkedList(l1);
    freeLinkedList(l2);
    freeLinkedList(result);

    return 0;
}
