#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//       1->2->3->null ���
// null<-1<-2<-3
ListNode* reverseList(ListNode* head) {
    if (head == nullptr)
        return nullptr;
    ListNode* p = head;
    ListNode* ans = new ListNode(p->val);
    while (p->next != nullptr) {
        ListNode* tmp = new ListNode(p->next->val);
        tmp->next = ans;
        ans = tmp;
        p = p->next;
    }
    return  ans;
}