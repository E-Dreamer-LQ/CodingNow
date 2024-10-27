// leetcode101-对称二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/symmetric-tree

#include <iostream>
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
   

 // 递归解决
class Solution {
public:
	bool dfs(TreeNode* left, TreeNode* right) {
		if (left == nullptr && right == nullptr) {
			return true;
		}
		if (!left || !right)
			return false;
		if (left->val != right->val) {
			return false;
		}
		// 镜像的原理， 左手对应镜子里面的右手，右手对应镜子里面的左手
		return dfs(left->left, right->right) && dfs(left->right, right->left);

	}
	bool isSymmetric(TreeNode* root) {
		return dfs(root, root);
	}
};

