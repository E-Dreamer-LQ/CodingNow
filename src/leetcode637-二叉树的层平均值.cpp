// leetcode637-二叉树的层平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/

#include <iostream>
#include <vector>
#include <queue>
using namespace std; 


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // 方法一,层序遍历法

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		queue<TreeNode*> que;
		if (root == nullptr) return res;
		que.push(root);
		while (!que.empty() || root) {
			int size = que.size();
			int val = size; 
			int sum = 0; 
			while (size--) {
				TreeNode* temp = que.front();
				sum += temp->val;
				que.pop();
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
			res.push_back(sum / val);
		}
		return res; 
	}
};

