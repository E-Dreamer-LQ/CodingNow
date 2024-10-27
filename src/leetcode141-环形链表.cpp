// leetcode141-环形链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/linked-list-cycle

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;



//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

// 方法1： 使用hashmap 
class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head == nullptr) return false;
		int pos;
		ListNode* cur = head;
		set<ListNode*> hash;
		while (cur != nullptr) {
			if (hash.find(cur) != hash.end()) { // 说明存在相同的节点
				return true;
			}
			else {
				hash.insert(cur);
				cur = cur->next;
			}
		}
		return false;

	}
};


// 方法二：双指针： 快慢指针
class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head == nullptr) return false;
		int pos;
		ListNode* slow = head;
		ListNode* fast = head->next;
		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) { return true; }
		}
		return false;
	}
};


