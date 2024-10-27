// newcoder14-链表中倒数第k个结点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std; 


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
// 复杂度过大，反转链表法
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* pNode = pListHead;
		ListNode* pPrev = nullptr;
		int i = 0;
		while (pNode != nullptr) {
			ListNode* pNext = pNode->next;
			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
			i++;
		}
		//while (pPrev) {
		//	cout << pPrev->val << endl;
		//	pPrev = pPrev->next;
		//}
		if (k > i) {
			return nullptr;
		}
		while (k--) {
			pPrev = pPrev->next;
		}
		return pPrev;
	}
};


// 双指针法
// 设置两个指针，p2指针先走（k-1）步，然后再一起走，当p2为最后一个时，p1就为倒数第k个 数
class Solution2 {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr || k <= 0) return nullptr;
		ListNode* p2 = pListHead;
		ListNode* p1 = pListHead;
		//p2先走，走k - 1步，如果k大于链表长度则返回 空，否则的话继续走
		while (k > 1)
		{
			if (p2->next != nullptr) {
				p2 = p2->next;
				k = k - 1;
			}
			else {
				return nullptr;
			}
		}
		//两个指针一起 走，一直到p2为最后一个, p1即为所求
		while (p2->next != nullptr) {
			p1 = p1->next; 
			p2 = p2->next;
		}
		return p1;
	}
};



void main() {
	Solution S;
	Solution S2;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	//ListNode* res = S.FindKthToTail(head,2);
	ListNode* res2 = S2.FindKthToTail(head, 2);
	//cout << res->val << endl; 
	cout << res2->val << endl; 
}

