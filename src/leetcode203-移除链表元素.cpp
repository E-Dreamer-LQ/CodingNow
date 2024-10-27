// leetcode203-移除链表元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/remove-linked-list-elements/

#include <iostream>
#include <vector>
using namespace std;


// 方法一: 直接讨论删除的节点情况
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 class Solution {
 public:
	 ListNode* removeElements(ListNode* head, int val) {
		 ListNode* p = head;//当前判断元素
		 ListNode* k = p;//用于指向前一个元素
		 while (p)
		 {
			 if (p->val == val) // 到达要删除的结点值时
			 {
				 if (p == head)//头元素要删的情况
				 {
					 head = p->next;
					 p = head;
					 if (head == NULL)
						 return head;
					 else continue;
				 }
				 else if (p->next == NULL)//末尾元素要删的情况
				 {
					 k->next = NULL;
					 return head;
				 }
				 else//中间元素
				 {
					 k->next = p->next;
					 p = k->next;
					 continue;
				 }
			 }
			 k = p; 
			 p = p->next;
		 }
		 return head;
	 }
 };

void printList(ListNode* head) {
	ListNode* cur = head;
	cout << "order: " << endl;
	while (cur != nullptr) {
		cout << cur->val + " ";
		cur->next;
	}
}

// 从头开始打印链表的结点
vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> allData;
	while (head != NULL) {
		allData.insert(allData.begin(), head->val);
		head = head->next;
	}
	return allData;
}

void main() {
	Solution S;
	int val = 6;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	vector<int>ori = printListFromTailToHead(head);
	for (int i = 0; i < ori.size(); i++) {
		cout << ori[i];
	}
	cout << endl;
	ListNode* res_Node = S.removeElements(head,val);
	vector<int>res = printListFromTailToHead(res_Node);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
	}
	cout << "completed" << endl;
}