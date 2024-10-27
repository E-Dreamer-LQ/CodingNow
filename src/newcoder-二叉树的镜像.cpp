// newcoder-二叉树的镜像.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	// dfs
	void Mirror(TreeNode* pRoot) {
		if (pRoot == nullptr) return;
		TreeNode* temp;
		temp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = temp;

		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};
