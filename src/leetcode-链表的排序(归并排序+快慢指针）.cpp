// leetcode-链表的排序(归并排序+快慢指针）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std; 


 //* Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 // 递归版本
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 递归版本
 class Solution {
 public:
	 ListNode* sortList(ListNode* head) {
		 if (!head || !head->next) return head;

		 ListNode* slow = head, * fast = head->next;
		 while (fast && fast->next) {
			 slow = slow->next;
			 fast = fast->next->next;
		 }

		 ListNode* left = sortList(slow->next);
		 slow->next = NULL;
		 ListNode* right = sortList(head);
		 return merge(left, right);
	 }


	 ListNode* merge(ListNode* left, ListNode* right) {
		 ListNode* dummy = new ListNode(0);
		 ListNode* p = dummy;
		 while (left && right) {
			 if (left->val < right->val) {
				 p->next = left;
				 left = left->next;
			 }
			 else {
				 p->next = right;
				 right = right->next;
			 }
			 p = p->next;
		 }
		 if (left) p->next = left;
		 if (right) p->next = right;
		 return dummy->next;
	 }
 };




