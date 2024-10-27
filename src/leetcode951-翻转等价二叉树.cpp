// leetcode951-翻转等价二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/flip-equivalent-binary-trees

#include <iostream>
using namespace std;

/*
如果 root1 或者 root2 是 null，那么只有在他们都为 null 的情况下这两个二叉树才等价。
如果 root1，root2 的值不相等，那这两个二叉树的一定不等价。
如果以上条件都不满足，也就是当 root1 和 root2 的值相等的情况下，需要继续判断 root1 的孩子节点是不是跟 root2 的孩子节点相当。因为可以做翻转操作，所以这里有两种情况需要去判断。
*/


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // 三步走
class Solution {
public:
	bool flipEquiv(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 != nullptr) return false;
		if (root1 != nullptr && root2 == nullptr) return false;
		if (root1 == nullptr && root2 == nullptr) return true;
		if (root1->val != root2->val) return false;
		return (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left) ||
			flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right));
	}
};

