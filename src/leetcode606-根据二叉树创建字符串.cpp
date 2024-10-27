// leetcode606-根据二叉树创建字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/construct-string-from-binary-tree

#include <iostream>
#include <string>
#include <stack>
using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 // 前序遍历
class Solution {
public:
	string tree2str(TreeNode* t) {
		string res = "";
		stack<TreeNode*> sta;
		if (t == nullptr) return res;
		sta.push(t);
		TreeNode* cur = t;
		while (!sta.empty()) {
			TreeNode* tmp = sta.top();
			sta.pop();
			if (tmp->right != nullptr) sta.push(tmp->right);
			if (tmp->left != nullptr) sta.push(tmp->left);
		}


	}
};

// 来自别人
class Solution {
public:

	void preAccess(TreeNode* t, string& str)
	{
		if (t == NULL) return;
		str += to_string(t->val);
		if (t->left || t->right)
		{
			str += "(";
			preAccess(t->left, str);
			str += ")";
		}
		if (t->right)
		{
			str += "(";
			preAccess(t->right, str);
			str += ")";
		}
	}

	string tree2str(TreeNode* t) {
		string res = "";
		preAccess(t, res);
		return res;
	}
};

