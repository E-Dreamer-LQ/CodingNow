// leetcode138-复制带随机指针的复杂链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 题目链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer/

#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	//Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) {
			return head;
		}
		//1. 遍历链表，将原节点作为key，拷贝节点作为value保存在map中
		unordered_map<Node*, Node*> hashmap;
		Node* cur = head;
		while (cur != nullptr) {
			Node* copy = new Node (cur->val,cur->next,cur->random);
			hashmap[cur] = copy;
			cur = cur->next;
		}
		// 拷贝next 指针和random指针
		cur = head;
		while (cur != nullptr) {
			hashmap[cur]->next = hashmap[cur->next];
			hashmap[cur]->random = hashmap[cur->random];
			cur = cur->next;
		}
		return hashmap[head];
	}
};


// 方法二 : 原地复制
class Solution2 {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) {
			return head;
		}
		Node* cur = head;
		Node* next = nullptr;
		//第一遍扫描：对每个结点进行复制，把复制出来的新结点插在原结点之后
		while (cur != nullptr) {
			next = cur->next;
			cur->next = new Node(cur->val,cur->next,cur->random);
			cur->next->next = next;
			cur = next;
		}
		cur = head;
		Node* curCopy = nullptr;
		// 第二遍扫描：根据原结点的random，给新结点的random赋值  
		while (cur != nullptr) {
			next = cur->next->next;
			curCopy = cur->next;
			curCopy->random = cur->random != nullptr ? cur->random->next : nullptr;
			cur = next;
		}
		// 将拷贝的节点分离, 拷贝的节点从第二个节点开始
		Node* res = head->next;
		cur = head;
		while (cur != nullptr) {
			next = cur->next->next;
			curCopy = cur->next;
			cur->next = next;
			curCopy->next = next != nullptr ? next->next : nullptr;
			cur = next;
		}
		return res;
	}
};

void printRandLinkedList(Node* head) {
	Node* cur = head;
	cout << "order: " << endl;
	while (cur != nullptr) {
		cout << cur->val + " ";
		cur->next;
	}
	cur = head;
	cout << "Random: " << endl;
	while (cur != nullptr) {
		if (cur->random == nullptr) 
			cout << " ";
		else {
			cout << cur->random->val + " ";
		}
		cur->next;
	}
}

// 验证
void main() {
	Solution S;
	Solution S2;
	Node* head = nullptr;
	Node* res1 = nullptr;
	Node* res2 = nullptr;
	//printRandLinkedList(head);
	//res1 = S.copyRandomList(head);
	//printRandLinkedList(res1);
	//res2 = S2.copyRandomList(head);
	//printRandLinkedList(res2);
	cout << "----------------------" << endl;

	head = new Node(1,nullptr,nullptr);
	head->next = new Node(2, head->next, head->random);
	head->next->next = new Node(3, head->next, head->random);
	head->next->next->next = new Node(4, head->next, head->random);
	head->next->next->next->next = new Node(4, head->next, head->random);
	head->next->next->next->next->next = new Node(6, head->next, head->random);

	head->random = head->next->next->next->next->next;
	head->next->random = head->next->next->next->next->next;
	head->next->next->random = head->next->next->next->next;
	head->next->next->next->random = head->next->next;
	head->next->next->next->next->random = nullptr;
	head->next->next->next->next->next->random = head->next->next->next;
	res1 = S.copyRandomList(head);
	printRandLinkedList(res1);
	res2 = S2.copyRandomList(head);
	printRandLinkedList(res2);
	cout << "----------------------" << endl;
}
