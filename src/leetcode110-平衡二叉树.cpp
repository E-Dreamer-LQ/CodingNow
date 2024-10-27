// leetcode110-平衡二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/balanced-binary-tree/

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

// 方法一： 从低至顶（提前阻断法）

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		return process(root) != -1;
	}
	int process(TreeNode* root) {
		if (root == nullptr) return 0;//当DFS越过叶子节点时，返回高度0
		int left = process(root->left);
		if (left == -1) {
			return -1;
		}
		int right = process(root->right);
		// 如果提前判断为不满足二叉树结构，就直接返回
		if (right == -1) {
			return -1;
		}
		return abs(left - right) < 2 ? max(left, right) + 1 : -1;
	}
};


// 方法二: 递归求高度,递归博客：http://39.96.217.32/blog/4
class Solution2 {
public:
	// 求高度
	int height(TreeNode* node) {
		if (node == nullptr) return 0; // 递归终止条件
		return max(height(node->left) + 1, height(node->right) + 1); // 递归
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		int left = height(root->left);
		int right = height(root->right);
		return (abs(left - right) < 2 && isBalanced(root->left) && isBalanced(root->right));
	}
};


