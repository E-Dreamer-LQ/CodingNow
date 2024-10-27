// leetcode814-二叉树剪枝.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/binary-tree-pruning

#include <iostream>
using namespace std;



namespace test {  //写成代码块

	// Definition for a binary tree node.
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class Solution {
	public:

		TreeNode* pruneTree(TreeNode* root) {
			if (root == nullptr) return nullptr;
			TreeNode* left = pruneTree(root->left);
			TreeNode* right = pruneTree(root->right);
			if (left == nullptr && right == nullptr && root->val == 0) {
				return nullptr;
			}
			return root;
		}
	};

}
