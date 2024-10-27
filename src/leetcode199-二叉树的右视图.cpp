// leetcode199-二叉树的右视图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/binary-tree-right-side-view/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			while (size--) {
				TreeNode* temp = que.front();
				if (size == 0) {
					res.push_back(temp->val);
				}
				que.pop();
				que.push(temp->left == nullptr ? nullptr : temp->left);
				que.push(temp->right == nullptr ? nullptr : temp->right);
			}
		}
		return res;
	}
};


// 也可以先加入右边孩子、再加入左边孩子
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			res.push_back(que.front()->val);
			while (size--) {
				TreeNode* tmp = que.front();
				que.pop();
				// 从右向左入队列
				if (tmp->right) que.push(tmp->right);
				if (tmp->left)  que.push(tmp->left);
			}
		}
		return res;
	}
};