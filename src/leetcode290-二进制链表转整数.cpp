// leetcode290-二进制链表转整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer

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
	ListNode* reverse(ListNode* head) {
		ListNode* pPrev = nullptr;
		ListNode* pNode = head;
		while (pNode) {
			ListNode* pNext = pNode->next;
			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
		}
		return pPrev;  // 这里返回的是pPrev 
	}
	int getDecimalValue(ListNode* head) {
		if (head == nullptr) return 0;
		int res = 0;
		int temp = 1;
		// 首先反转链表
		//ListNode* cur = reverse(head);
		//ListNode* pPrev = nullptr;
		//while (head) {
		//	ListNode* pNext = head->next;
		//	head->next = pPrev;
		//	pPrev = head;
		//	head = pNext;
		//}
		ListNode* cur = reverse(head);  // 注意这里
		while (cur!=nullptr) {
			res += (cur->val * temp);
			temp *= 2;
			cur = cur->next;
		}
		return res;
	}

};
//class Solution2 {
//public:
//	int getDecimalValue(ListNode* head) {
//		ListNode* pre = nullptr;
//		while (head != nullptr) {
//			ListNode* next = head->next;
//			head->next = pre;
//			pre = head;
//			head = next;
//		}
//		int sum = 0;
//		int tmp = 1;
//		while (pre != nullptr) {
//			sum += (pre->val * tmp);
//			tmp *= 2;
//			pre = pre->next;
//		}
//		return sum;
//	}
//};

void main() {
	Solution S;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(0);
	head->next->next = new ListNode(1);
	int res = S.getDecimalValue(head);
	cout << res << endl;

}