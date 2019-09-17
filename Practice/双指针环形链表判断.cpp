#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head){
    if (head == nullptr)
        return false;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (p2->next != nullptr) {
        p1 = p1->next;
        if (p1->next == nullptr)
            return false;
        if (p2->next->next == nullptr)
            return false;
        p2 = p2->next->next;
        if (p1 == p2)
            return true;
    }
    return false;
}

void hasCycleTest() {
    ListNode a1(1), a2(2), a3(3), a4(4);
    a1.next = &a2;
    a2.next = &a3;
    a3.next = &a4;
    a4.next = &a2;
    hasCycle(&a1);
}