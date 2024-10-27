// leetcode965-单值二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/univalued-binary-tree/

#include <iostream>
#include <stack>
using namespace std; 


// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
// 写法一
class Solution {
public:
	bool isUnivalTree(TreeNode* root) {
		return isUnival(root);

	}
	bool isUnival(TreeNode* root) {
		if (root == nullptr) return true;
		if ((root ->left && root->left->val != root->val)) {
			return false;
		}
		if ((root->right && root->right->val != root->val)) {
			return false;
		}
		return isUnival(root->left) && isUnival(root->right);
	}
};

// 中序遍历法 
bool isUnivalTree(TreeNode* root) {
	if (root == nullptr) return true;
	TreeNode* pre = nullptr;
	stack<TreeNode*> sta;
	TreeNode* cur = root;
	while (cur) {
		if (cur || !sta.empty()) {
			sta.push(cur->left);
			cur = cur->left;
		}
		else{
			cur = sta.top();
			sta.pop();
			if (pre && pre->val != cur->val) {
				return false; 
			}
			pre = cur;
			cur = cur->right;	
		}
	}
	return true;

}