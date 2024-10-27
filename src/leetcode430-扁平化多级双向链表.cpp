// leetcode430-扁平化多级双向链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list

#include <iostream>
#include <stack>
using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;
};
// 递归法实现
class Solution {
public:
	Node* flatten(Node* head) {
		if (head == nullptr) return nullptr;
		Node* temp = head;
		Node* nextnode = nullptr;
		Node* prevnode = head;
		while (prevnode != nullptr) {
			if (temp && temp->child) {
				nextnode = temp->next; // 记录当前节点的下一个节点
				temp->child->prev = temp;
				// 开始进入递归
				temp->next = flatten(temp->child);
				temp->child = nullptr; // 注销当前节点的child；
			}
			prevnode = temp;// 记录null节点的前一个节点
			if (temp) temp = temp->next;
			if (nextnode && !temp) {//当同一级链表存在下一个节点（即，原来有child的节点的下一节点），且子链表到达null
				prevnode->next = nextnode;//连接子节点和之前记录的nextnode所指链表 ---->这一步将其中两级双向链表扁平化
				nextnode->prev = prevnode;
				temp = prevnode->next;
				nextnode = nullptr; //记得清空使用过的nextnode，否则会将无限连接nextnode所指链表

			}
		}
		return head;

	}
};

// stack法
class Solution2 {
public:
	Node* flatten(Node* head) {
		if (head == nullptr) return nullptr;
		stack<Node*> stack;
		Node* cur;
		// 头结点入栈
		stack.push(head);
		Node* prev = nullptr;
		while (!stack.empty()) {
			cur = stack.top();
			stack.pop();
			if (cur->next) { // 先next的节点，后child节点。
				stack.push(cur->next);
			}
			if (cur->child) {
				stack.push(cur->child);
				cur->child = nullptr; //记得清空child指针
			}
			if (prev) {  // 构建双向链表
				prev->next = cur;
				cur->prev = prev;
			}
			prev = cur;
		}
		return head;


	}
};

// 


