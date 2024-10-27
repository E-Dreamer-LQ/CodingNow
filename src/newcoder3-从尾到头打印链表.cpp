// newcoder3-从尾到头打印链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include <stack>
using namespace std;


  struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

  // 反转链表法
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		if (head == nullptr) return res;
		ListNode* pNode = head;
		ListNode* pPrev = nullptr;
		while (pNode) {
			ListNode* pNext = pNode->next;
			pNode->next = pPrev;
			pPrev = pNode;
			pNode = pNext;
		}
		while (pPrev) {
			res.push_back(pPrev->val);
			cout << pPrev->val;
			pPrev  = pPrev->next;
		}
		return res;
	}
	void printListNode(ListNode* head) {
		while (head) {
			cout << head->val;
			head = head->next;
		}
	}
};


// 栈结构
class Solution2 {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> value;
		ListNode* p = NULL;
		p = head;
		stack<int> stk;
		while (p != NULL) {
			stk.push(p->val);
			p = p->next;
		}
		while (!stk.empty()) {
			value.push_back(stk.top());
			stk.pop();
		}
		return value;
	}

};

void main() {
	Solution S;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	//S.printListNode(head);
	vector<int> res = S.printListFromTailToHead(head);
	//for (auto num : res) {
	//	cout << num;
	//}

}