#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    head->next = deleteDuplicates(head->next);
    if (head->val == head->next->val)
        return head->next;
    else
        return head;
}