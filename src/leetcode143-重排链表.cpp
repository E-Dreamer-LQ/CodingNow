// leetcode143-重排链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/reorder-list

#include <iostream>
#include <vector>
using namespace std;


//* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 方法一： 将节点的指针加入到vector数组
class Solution {
public:
	void reorderList(ListNode* head) {
		vector<ListNode*> temp;
		if (head == nullptr) return;
		while (head != nullptr) {
			temp.push_back(head);
			head->next;
		}
		int left = 0, right = temp.size() - 1;
		while (left < right) {
			temp[left]->next = temp[right];
			temp[right--]->next = temp[left++];
		}
		// 注意
		temp[left]->next = nullptr;
	}

};

// 反转一个链表
ListNode* reverse(ListNode* head) {
	ListNode* pNode = head;
	ListNode* pPrev = nullptr;
	while (pNode != nullptr)
	{
		ListNode* pNext = pNode->next;//保存下一个节点的值
		pNode->next = pPrev;//把当前pNode的下一个节点指向pPrev,pNode、pPrev交替工作进行反向
		pPrev = pNode;//此时pPrev向后移动指向此时的pNode
		pNode = pNext;//而pNode也向后移动，指向刚才保存的pNext;
	}
	return pPrev;

}
// 方法二 ： 找中点方法  （难）
void reorderList2(ListNode* head) {
	if (head == nullptr) { return; }
	// 找到中点，定义一个快指针和一个慢指针
	ListNode* slow = head;
	ListNode* fast = head->next;
	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	// 逆转后半部分
	ListNode* right = reverse(slow->next);
	slow->next = nullptr;
	// 拼接前半部分和逆转过的后半部分
	ListNode* left = head;
	while (right != nullptr) {
		ListNode* next = right->next; // 用来存储right的下一个节点
		right->next = left->next;
		left->next = right;
		right = next;
		left = left->next->next;
	}
}
