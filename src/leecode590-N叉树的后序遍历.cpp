// leecode590-N叉树的后序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
// 先序遍历 小小改动
class Solution {
public:
	vector<int> postorder(Node* root) {
		stack<Node*> sta;
		vector<int> res; 
		if (root == nullptr)
			return res;    // 空树，直接返回
		sta.push(root);

		while(!sta.empty()){
			Node* temp = sta.top();
			res.push_back(temp->val);
			sta.pop();
			int len = temp->children.size(); 
			for (int i = 0; i < len; i++) {   // 注意和先序遍历的区别
				sta.push(temp->children[i]);
			}
		reverse(res.begin(), res.end());
		}
		return res;

	}
};