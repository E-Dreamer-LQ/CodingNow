// leetcode993-二叉树的堂兄节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/cousins-in-binary-tree

#include <iostream>
#include <stack>
using namespace std;

// 堂兄节点： 深度相同，父节点不同   （深度判断 + 父元素的值判断（因为没有重复的元素））


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:

	int xpar, xdep, ypar, ydep;
	bool isCousins(TreeNode* root, int x, int y) {
		dfs(root->left, 1, x, y, root->val);
		dfs(root->right, 1, x, y, root->val);
		return (xpar != ypar) && (xdep == ydep);

	}
	void dfs(TreeNode* node, int dep, int x, int y, int par) {
		if (node == nullptr) return;
		if (node->val == x) {
			xpar = par; // x的父节点值
			xdep = dep;  // x的深度
		}
		else if (node->val == y) {
			ypar = par;    // y的父节点值
			ydep = dep;  // y的深度
		}
		else {
			dfs(node->left, dep + 1, x, y, node->val);
			dfs(node->right, dep + 1, x, y, node->val);
		}
	}
};


/* java代码：
class Solution {
	int xpar, xdep, ypar, ydep;

	public boolean isCousins(TreeNode root, int x, int y) {
		dfs(root.left, 1, x, y, root.val);
		dfs(root.right, 1, x, y, root.val);
		return (xpar != ypar) && (xdep == ydep);
	}

	public void dfs(TreeNode node, int dep, int x, int y, int par) {
		if (node == null) {
			return;
		}
		if (node.val == x) {
			xpar = par;
			xdep = dep;
		} else if (node.val == y) {
			ypar = par;
			ydep = dep;
		} else {
			dfs(node.left, dep+1, x, y, node.val);
			dfs(node.right, dep+1, x, y, node.val);
		}
	}
}
*/