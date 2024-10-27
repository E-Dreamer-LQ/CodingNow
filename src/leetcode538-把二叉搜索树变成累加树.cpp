// leetcode538-把二叉搜索树变成累加树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/convert-bst-to-greater-tree

#include <iostream>
#include <stack>
using namespace std; 


// 首先必须明白二叉搜索树的概念:即左孩子比根小，右孩子比根大

//Definition for a binary tree node.
struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		if (root != nullptr) dfs(root, 0);
		return root;

	}
	int dfs(TreeNode* root, int sum) {
		if (root == nullptr) return sum;
		// 先将右孩子的值加入到根节点
		sum = dfs(root->right, sum);
		root->val += sum;
		// 再将sum值加入到左孩子
		sum = dfs(root->left, sum);
		return sum;

	}
};


// 方法二：类似中序遍历
class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr) return nullptr;
		stack<TreeNode*> sta;
		int sum=0;
		TreeNode* cur = root;
		while (!sta.empty() || cur) {
			if (cur) {
				sta.push(cur);
				cur = cur->right;
			}
			cur = sta.top();
			sta.pop();
			// 将右孩子的值累加，和根节点累加后赋值给根节点
			sum += cur->val;
			cur->val = sum;
			cur = cur->left;
		}
		return cur;
	}

};

