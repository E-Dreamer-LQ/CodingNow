// leetcode617-合并二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/merge-two-binary-trees

#include <iostream>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr) return t2;
		if (t2 == nullptr) return t1;
		if (t1 == nullptr && t2 == nullptr) return nullptr;
		if (t1 && t2) {
			t1->val += t2->val;
			t1->left = mergeTrees(t1->left, t2->left);
			t1->right = mergeTrees(t1->right, t2->right);
			return t1;
		}
	}
};
