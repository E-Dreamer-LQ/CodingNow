// leetcode92-反转链表 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/reverse-linked-list-ii



#include <iostream>


//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
// 方法一
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (head == nullptr) return nullptr;
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		for (int i = 1; i < m; i++) {
			pre = pre->next;
		}
		ListNode* cur = pre->next;
		for (int i = m; i < n; i++) {
			ListNode* pNext = cur->next;
			cur->next = pNext->next; //  1->2->4->5  (断开节点2和3，将2连到4)
			pNext->next = pre->next; //  将3 的节点连到2前面，1后面
			pre->next = pNext; // 1连到2的节点断开，1连 后面连结点3
		}
		return dummy->next; // 就算是原来头结点变了也没事
	}
};
