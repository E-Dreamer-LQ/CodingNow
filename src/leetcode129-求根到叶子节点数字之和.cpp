// leetcode129-求根到叶子节点数字之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


// Definition for a binary tree node.
  struct TreeNode {
      int val;
	  TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public://一版
	int helper(TreeNode* root, int sum) {
		if (root == nullptr)
			return 0;
		else if (!root->left && !root->right)
			return 10 * sum + root->val;
		return helper(root->left, 10 * sum + root->val) +
			helper(root->right, 10 * sum + root->val);
	}
	int sumNumbers(TreeNode* root) {
		return helper(root, 0);
	}
};

