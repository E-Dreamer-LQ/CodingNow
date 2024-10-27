// leetcode563-二叉树的坡度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/binary-tree-tilt

#include <iostream>


 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
	int findTilt(TreeNode* root) {
		if (root == nullptr) return 0;
		int left = count(root->left);
		int right = count(root->right);
		return abs(left - right);

	}
	int count(TreeNode* root) {
		int val = 0;
		while (root) {
			val += root->val;
		}
		return val;
	}
};


