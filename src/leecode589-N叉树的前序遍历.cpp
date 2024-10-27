// leecode589-N叉树的前序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//   先序中入栈顺序先右后左 --> 孩子节点数组从右向左入栈
//   后序中入栈顺序先左后右 --> 孩子节点数组从左向右入栈

#include <iostream>
#include <vector>
#include <stack>
using namespace std; 


/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};
*/

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
}; 

class Solution {
public:
	vector<int> preorder(Node* root) {

		stack<Node*> sta;
		vector<int> res;
		if (root == nullptr) return res; // 空树，直接返回
		sta.push(root);
		while (!sta.empty()) {
			Node* temp = sta.top();
			res.push_back(temp->val);
			sta.pop();
			int len = temp ->children.size();
			for (int i = len - 1; i >= 0; i--) {   // 二叉树是先将右孩子入栈，再是左孩子
				if (temp->children[i])
					sta.push(temp->children[i]);
			}
		}
	}
};
