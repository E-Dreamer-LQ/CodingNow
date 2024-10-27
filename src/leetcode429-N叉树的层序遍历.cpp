// leetcode429-N叉树的层序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int>> levelOrder(Node* root) {
		queue<Node*> que;
		vector<vector<int>> res; 
		if (root == nullptr) return res;  // 树为空，直接返回
		Node* cur = root;
		while (!que.empty) {
			int size = que.size();
			vector<int> level;
			while (size--) {
				Node* temp = que.front();
				que.pop();
				level.push_back(temp->val);
				for (auto child : temp->children) {
					if (child != nullptr)
						que.push(child);
				}
			}
			res.push_back(level);
		}
		return res;
	}
};

