#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//当访问 A 链表的指针访问到链表尾部时，令它从链表 B 的头部开始访问链表 B；
//同样地，当访问 B 链表的指针访问到链表尾部时，令它从链表 A 的头部开始访问链表 A。
//这样就能控制访问 A 和 B 两个链表的指针能同时访问到交点。
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr)
        return NULL;
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    //int flag = 0;
    while (p1 != p2) {
        //if (p1->next == nullptr)
        //   flag++;
        //if (flag == 2)
        //    return NULL;
        p1 = p1 == nullptr ? headB : p1->next;
        p2 = p2 == nullptr ? headA : p2->next;
    }
    return p1;
}