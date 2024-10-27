// leetcode147-对链表进行插入排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/insertion-sort-list/

#include <iostream>


/*
想要排序块，就要尽可能少的做比较
需要一个指针指向当前已排序的最后一个位置，这里用的是head指针
需要另外一个指针pre,每次从表头循环，这里用的是dummy表头指针。
每次拿出未排序的节点，先和前驱比较，如果大于或者等于前驱，就不用排序了，直接进入下一次循环
如果前驱小，则进入内层循环，依次和pre指针比较，插入对应位置即可
*/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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


/*
首先判断两个相邻节点的大小，如果head->val > head->next->val，
则需要将head->next->val插入到从dummy节点开始遍历第一个大于head->next->val节点的前面！
好好理解这句话！在进行插入的时候，首先使用cur指针标记head->next节点，
并改变head->next的指向。从而将待插入节点分离！接着就是普通的插入操作了！
*/