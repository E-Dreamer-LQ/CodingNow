// leetcode142-环形链表II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/linked-list-cycle-ii

#include <iostream>




 //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

// 方法： 快慢指针法 
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == nullptr) { return head;}
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow) {   // 快慢指针第一次相遇，跳出循环
				break;
			}
		}
		if (fast == nullptr)  return nullptr; // 这是无环的情况
		// 第二次相遇
		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
	}
};
