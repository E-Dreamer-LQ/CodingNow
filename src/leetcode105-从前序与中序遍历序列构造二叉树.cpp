// leetcode105-从前序与中序遍历序列构造二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 找到根节点  ——   构建左孩子  ——  构建右孩子+

#include <iostream>
#include <vector> 
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return nullptr;
		int i = 0;
		while (inorder[i] != preorder[0]) {   // 找到中序中树根的位置
			i++;  
		}
		TreeNode* root = new TreeNode(preorder[0]);
		// 注意去除第一个preorder[0]
		vector<int> preleft(preorder.begin() + 1, preorder.begin() + 1 + i);
		vector<int> preright(preorder.begin() + i + 1, preorder.end());
		vector<int> inleft(inorder.begin(), inorder.begin() + i);
		vector<int> inright(inorder.begin() + i+1, inorder.end());
		root->left = buildTree(preleft, inleft);
		root->right = buildTree(preright, inright);
		return root;
	}
};