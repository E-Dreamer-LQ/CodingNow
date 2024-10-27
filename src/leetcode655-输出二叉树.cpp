// leetcode655-输出二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/print-binary-tree

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
	vector<vector<string>> printTree(TreeNode* root) {
		
		// 求二叉树高度
		int m = dfs(root);
		// 求二叉树宽度
		int n = pow(2, m) - 1; // n = 2^m-1 
		vector<vector<string>> res(m, vector<string>(n, "")); // m*n的二维
		// 打印
		dfsPrint(root, res, 0, 0, n - 1);
		return res;
	}
	int dfs(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(dfs(root->left), dfs(root->right) + 1);
	}
	// 二分法打印输出
	void dfsPrint(TreeNode* root, vector<vector<string>> res, int row, int start, int end) {
		if (!root || (start > end)) return;
		int mid = start + (end - start) / 2;
		res[row][mid] = to_string(root->val); 
		dfsPrint(root->left, res, row + 1, start, mid);
		dfsPrint(root->right, res, row + 1, mid + 1, end);
	}
};
