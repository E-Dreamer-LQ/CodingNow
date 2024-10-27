// leetcode106-从中序与后序遍历序列构造二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0) return nullptr;
		int i = 0;
		int size = postorder.size();
		while (inorder[i] != postorder[size - 1]) {
			i++;
		}
		TreeNode* root = new TreeNode(postorder[size-1]);
		vector<int> inleft(inorder.begin(), inorder.begin() + i);
		vector<int> inright(inorder.begin() + i, inorder.end());
		vector<int> postleft(postorder.begin(), postorder.begin() + i);
		vector<int> postright(postorder.begin() + i, postorder.end() - 1);
		root->left = buildTree(inleft, inright);
		root->right = buildTree(postleft, postright);
		return root;
	}
};


