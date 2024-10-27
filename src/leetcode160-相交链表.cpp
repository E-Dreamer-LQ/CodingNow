// leetcode160-相交链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

 // Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;
		ListNode* preA = headA;
		ListNode* preB = headB;

		while (preA && preB) {
			preA = preA == nullptr ? nullptr : preA->next;
			preB = preB == nullptr ? nullptr : preB->next;
		}
		return preA;
	}
};

class Solution2 {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;
		ListNode* preA = headA;
		ListNode* preB = headB;

		while (preA && preB) {
			if (preA->val == preB->val) {
				ListNode* nextA = preA->next;
				ListNode* nextB = preB->next;
				if (nextA == nextB) {
					return preA;
				}
			}
			preA = preA->next;
			preB = preA->next;

		}
		return preA;
	}
};


void main() {
	Solution S;
	Solution2 S2;
	ListNode* headA = new ListNode(4);
	headA->next = new ListNode(1);
	headA->next->next = new ListNode(8);
	headA->next->next->next = new ListNode(4);
	headA->next->next->next->next = new ListNode(5);
	ListNode* headB = new ListNode(5);
	headB->next = new ListNode(0);
	headB->next->next = new ListNode(1);
	headB->next->next->next = new ListNode(8);
	headB->next->next->next->next = new ListNode(4);
	headB->next->next->next->next->next = new ListNode(5);
	ListNode* res = S.getIntersectionNode(headA, headB);
	ListNode* res2 = S2.getIntersectionNode(headA, headB);
	cout << res << endl;
	cout << res2 << endl;
}
