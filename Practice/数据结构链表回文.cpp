#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return true;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow;
    ListNode* tail = new ListNode(slow->val);
    while (slow->next != nullptr) {
        ListNode* tmp = new ListNode(slow->next->val);
        tmp->next = tail;
        tail = tmp;
        slow = slow->next;
    }
    while (tail->next != nullptr) {
        if (tail->val == head->val) {
            tail = tail->next;
            head = head->next;
        }
        else
            return 0;
    }
    return 1;
}

void isPalindromeTest() {
    ListNode a1(1), a2(2), a3(3), a4(2),a5(1);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a5;
    isPalindrome(&a1);
}