#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr)
        return nullptr;
    else if (l1 == nullptr)
        return l2;
    else if (l2 == nullptr)
        return l1;
    ListNode* ans = nullptr;
    if (l1->val < l2->val) {
        ans = l1;
        ans->next = mergeTwoLists(l1->next, l2);
    }
    else {
        ans = l2;
        ans->next = mergeTwoLists(l1, l2->next);
    }
    return ans;
}

void mergeTwoListsTest() {
    ListNode l11 = 1; ListNode l12 = 2; ListNode l13 = 4;
    l11.next = &l12; l12.next = &l13;
    ListNode l21 = 1; ListNode l22 = 3; ListNode l23 = 4;
    l21.next = &l22; l22.next = &l23;
    ListNode* a = mergeTwoLists(&l11, &l21);
}