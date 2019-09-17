#include<iostream>
#include<math.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    ListNode zerosum(0);
    ListNode* head = new ListNode(0);
    ListNode* current = head;

    while (l1 || l2) {

        sum = (l1->val + l2->val) + sum;
        current->val = sum % 10;
        sum /= 10;
        if (l1->next != nullptr || l2->next != nullptr || sum != 0) {
            current->next = new ListNode(0);
            l1 = (l1->next != nullptr) ? l1->next : &zerosum;
            l2 = (l2->next != nullptr) ? l2->next : &zerosum;
            current = current->next;
        }
        else
            break;
    }
    return head;
}

void listnodetest() {
    ListNode L11(9), L12(0), L13(0);
    L11.next = &L12; L12.next = &L13;
    ListNode L21(9), L22(9), L23(1);
    L21.next = &L22; L22.next = &L23;

    std::cout << addTwoNumbers(&L11, &L21)->val;
}