// leetcode445-两数相加 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/add-two-numbers-ii/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


 // 链表的加法   (OJ 超出时间限制  ？？？？？)
 class Solution {
 public:
	 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 ListNode* p1 = l1;
		 ListNode* p2 = l2;
		 ListNode* res = new ListNode(0);
		 bool carry = false;
		 while (l1  || l2 ) {
			 int r1 = l1 ==nullptr ? 0 : l1->val;
			 int r2 = l2 == nullptr ? 0 : l2->val;
			 int sum = r1 + r2 + (carry ? 1 : 0);
			 carry = (sum >= 10);         // carry = sum/10     
			 ListNode* newNode = new ListNode(sum % 10);
			 newNode->next = res->next;
			 res->next = newNode;
			 if (l1->next == nullptr) l1 = l1->next;
			 if (l2->next == nullptr) l2 = l2->next;
		 }
		 if (carry) {
			 ListNode* newNode = new ListNode(1);
			 newNode->next = res->next;
			 res->next = newNode;
		 }
		 return res->next;
	 }
 };



// 两数相加II
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<ListNode*> sta1;
		stack<ListNode*> sta2;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		ListNode* res = new ListNode(0);
		bool carry = false;                
		while (p1 != nullptr) {
			sta1.push(p1);
			p1 = p1->next;
		}
		while (p2 != nullptr) {
			sta2.push(p2);
			p2 = p2->next;
		}
		while (!sta1.empty() || !sta2.empty()) {
			int r1 = sta1.empty() ? 0 : sta1.top()->val;
			int r2 = sta2.empty() ? 0 : sta2.top()->val;
			int sum = r1 + r2 + (carry ? 1 : 0);
			carry = (sum >= 10);         // carry = sum/10     
			ListNode* newNode = new ListNode(sum % 10);
			newNode->next = res->next;
			res->next = newNode;
			if (!sta1.empty()) sta1.pop();
			if (!sta2.empty()) sta2.pop();
		}
		if (carry) {
			ListNode* newNode = new ListNode(1);
			newNode->next = res->next;
			res->next = newNode;
		}
		return res->next;
	}
};
