// leetcode543-二叉树的直径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/diameter-of-binary-tree/

#include <iostream>
#include <algorithm>
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
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == nullptr) return 0;
		int left = dfs(root->left);
		int right = dfs(root->right);
		return left + right ;
		
	}
	int dfs(TreeNode* node) {
		if (node == nullptr) return 0;
		return max(dfs(node->left), dfs(node->right) + 1);
	}
};