// leetcode817-链表组件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/linked-list-components

#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
// 组件的定义：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。
// 方法一
class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		if (head == nullptr || G.size() == 0) { return 0; }
		int res = 0;
		map<int,int> hash;
		ListNode* p = new ListNode(-1);
		p->next = head;
		for (auto num : G) {
			hash[num]++;
		}
		if (p->next == nullptr) { // 空链表
			if (hash[p->val])
				return 1;
			else
				return 0;
		}
		while (p->next != nullptr) {
			if (!hash[p->val] && hash[p->next->val]) // 链表在G中如果存在断点
				res++;
			p = p->next;
		}
		return res;

	}
};


void main() {
	Solution S;
	ListNode* head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	vector<int> G{0,3,1,4};
	int res = S.numComponents(head, G);
	cout << res << endl;
	
}

// 方法二

