// leetcode-链表的插入排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std; 

struct ListNode {
	int val; 
	ListNode* next; 
	ListNode(int x): val(x),next(nullptr){}

};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head; 
		ListNode* dummy = new ListNode(0), * pre = nullptr;
		dummy->next = head;
		while (head->next != nullptr) {
			if (head->val <= head->next->val) {  // 无需进行插入操作
				head = head->next;
				continue;
			}
			pre = dummy;
			while (pre->next->val < head->next->val) {
				pre = pre->next;
			}
			ListNode* cur = head->next;
			head->next = cur->next;
			cur->next = pre->next;
			pre->next = cur;
		}
		return dummy->next;
	}
};

