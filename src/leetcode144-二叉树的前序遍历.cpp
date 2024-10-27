// leetcode144-二叉树的前序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  二叉树的前序遍历： 根节点 -》 左子数 -》 右子树

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> sta;
		vector<int> res; // 返回的数组
		if (root == nullptr) return res; // 判断根节点,空树，直接返回
		sta.push(root);
		while (!sta.empty()) {
			TreeNode* tmp = sta.top();
			sta.pop();
			if (tmp->right != nullptr) sta.push(tmp->right);
			if (tmp->left != nullptr) sta.push(tmp->left);
			res.push_back(tmp->val);
		}
		return res;
	}
};