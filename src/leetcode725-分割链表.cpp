// leetcode725-分割链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/split-linked-list-in-parts

#include <iostream>
#include<vector>
using namespace std;



 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		int length = 0;
		ListNode* cur = root;
		while (cur) {
			length += 1;
			cur = cur->next;
		}
		int nums = length / k;
		int left = length % k;
		cur = root;
		ListNode* pre = nullptr; //利用pre节点得到每个区间的最后一个节点 


		//vector<ListNode*> res(k, nullptr); // 已经分段
		//for (int i = 0; i < k; i++) {   //数组有k个元素需要遍历k次
		//	res[i] = cur;
		//	int tempLength = left > 0 ? (nums + 1) : nums; //相邻不超过1
		//	for (int j = 0; j < tempLength; j++) {
		//		pre = cur;
		//		cur = cur->next;
		//	}
		//	if (pre) pre->next = nullptr; //一个子链表已经生成，断开连接
		//	if (left) left--;
		//}
		//return res;



		vector<ListNode*> res;
		// 开始遍历
		while (cur != nullptr) {
			int tmp_nums = left ? nums + 1 : nums;  //相邻不超过1
			if (left > 0)  left -= 1;    // left >= 0
			res.push_back(cur); // 加入的是一个子链表头结点
			while (tmp_nums--) {
				pre = cur;
				cur = cur->next;
			}
			if (pre)  pre->next = nullptr;   // 进行链表分割
		}
		int tt = k - res.size(); 
		while (tt--) // 如果res.size 比 k 更小
			res.push_back(nullptr);
		return res;
	}
};


