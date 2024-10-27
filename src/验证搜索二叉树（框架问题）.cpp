// 验证搜索二叉树（框架问题）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
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
	TreeNode* preNode;
	bool isValidBST(TreeNode* root) {
		// 中序遍历是否是升序序列
		if (root == nullptr) return true;
		if (!isValidBST(root->left)) return false;
		if (preNode && preNode->val >= root->val) { // 判断条件
			return false;
		}
		preNode = root;
		if (!isValidBST(root->right)) return false;
		return true;
	}
};


// 方法2：
class Solution {
public:
	bool isValid(TreeNode* current, long left, long right) {
		if (current == nullptr) return true;
		else if (current->val <= left || current->val >= right) return false;
		return isValid(current->left, left, current->val)
			&& isValid(current->right, current->val, right);
	}
	bool isValidBST(TreeNode* root) {
		return isValid(root, LONG_MIN, LONG_MAX);  // 使用INT_MIN 和 INT_MAX溢出
	}
};


