// leetcode234-回文链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/palindrome-linked-list/

#include <iostream>


//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
// 方法一： 
class Solution {
public:
	ListNode* reverse(ListNode* head) {   
		ListNode* pNode = head;    // 看图理解：https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/
		ListNode* pPrev = nullptr;
		while (pNode != nullptr) {
			ListNode* pNext = pNode->next;
			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
		}
		return pPrev;

	}
	bool isPalindrome(ListNode* head) {
		if (head == nullptr) { return false; }
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* mid = slow;
		// 反转mid到尾结点的链表
		ListNode* right = reverse(mid->next);
		ListNode* left = head;
		//左半部分和反转后的右半部分
		while (left && right) {
			if (left->val != right->val) {
				return false;
			}
			left = left->next;
			right = right->next;
		}
		return true;

	}
};