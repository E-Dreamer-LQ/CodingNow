// leetcode382-链表的随机节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/linked-list-random-node

#include <iostream>


 // Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	/** @param head The linked list's head.
		Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		while (head != nullptr) {
			size++;
			head = head->next;
		}
	}

	/** Returns a random node's value. */
	int getRandom() {
		ListNode* cur = phead;
		int k = rand() % size;   //示随机生成一个数，范围在 0 ~ ( size -1 )之间
		for (int i = 0; i < k; i++) {
			cur = cur->next;
		}
		return cur->val;
	}
private:
	ListNode* phead;
	int size = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

