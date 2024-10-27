// leetcode206-反转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/reverse-linked-list/
#include <iostream>



// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) { return head; }
		ListNode* pNode = head;
		ListNode* pPrev = nullptr;
		while (pNode) {
			ListNode* pNext = pNode->next;
			pNode->next = pPrev;  
			pPrev = pNode;  // pPrev 后移
			pNode = pNext;  //  pNode 后移
		}
		return pPrev;
	}


	// 使用函数递归法

	ListNode* ReverseList(ListNode* pLast, ListNode* pHead)
	{
		ListNode* pTmp = pHead->next;
		pHead->next = pLast;
		if (pTmp == nullptr) { return pHead; }
		return ReverseList(pHead, pTmp);
	}

	ListNode* reversedList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head; 
		ListNode* p = reversedList(head->next); 
		head->next->next = head; 
		head->next = nullptr; 
		return p; 
	}
};

