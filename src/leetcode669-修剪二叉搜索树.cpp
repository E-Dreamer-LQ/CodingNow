// leetcode669-修剪二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/trim-a-binary-search-tree

#include <iostream>


/*
假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };




class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (root == nullptr)  return root;
		// 处理异常节点，将root->right提升为root
		if (root->val < L)
			return trimBST(root->right, L, R);
		if (root->val > R)
			return trimBST(root->left, L, R);
		// 处理正常的节点
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		return root;
	}
};

