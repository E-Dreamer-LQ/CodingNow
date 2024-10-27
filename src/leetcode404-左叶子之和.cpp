// leetcode404-左叶子之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/sum-of-left-leaves

#include <iostream>



 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr) return 0;
		int left = count(root->left);
		int right = count(root->right);
		return left + right;

		}

	int count(TreeNode* root){
		int sum = 0;
		if (root == nullptr) return 0;
		while (root->left) {
			sum += root->left->val;
		}
		return sum; 
	}
};


class Solution2 {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left && root->left->left == nullptr && root->left->right == nullptr)   // 左节点存在
			return root->left->val + sumOfLeftLeaves(root->right);
		else
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
};


