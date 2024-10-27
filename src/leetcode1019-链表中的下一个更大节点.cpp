// leetcode1019-链表中的下一个更大节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/next-greater-node-in-linked-list

#include <iostream>
#include<vector>
#include <stack>
using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

//正确解法
class Solution2 {
public:
	vector<int> nextLargerNodes(ListNode* head) {
		vector<int> res;
		stack<int> datastack;
		int i = 0;

		while (head != nullptr) {
			while (!datastack.empty() && head->val > res[datastack.top()]) {
				cout << datastack.top();
				res[datastack.top()] = head->val;
				datastack.pop();
			}

			res.push_back(head->val);
			datastack.push(i++); // 先添加 0 再 i+1 ，压入的是位置
			head = head->next;
		}

		while (!datastack.empty()) {
			res[datastack.top()] = 0;
			datastack.pop();
		}

		return res;
	}
};

void main() {
	Solution2 S;
	ListNode* head = new ListNode(2); //[2,7,4,3,5]
	head->next = new ListNode(7);
	head->next->next = new ListNode(4);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(5);
	vector<int> res = S.nextLargerNodes(head);
	//vector<int> ::iterator it;
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
}