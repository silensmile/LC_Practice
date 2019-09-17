#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//������ A �����ָ����ʵ�����β��ʱ������������ B ��ͷ����ʼ�������� B��
//ͬ���أ������� B �����ָ����ʵ�����β��ʱ������������ A ��ͷ����ʼ�������� A��
//�������ܿ��Ʒ��� A �� B ���������ָ����ͬʱ���ʵ����㡣
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