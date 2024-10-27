// leetcode515-在每个数行中找最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
	vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		if (root == nullptr) return res;
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			int max_value  = INT_MIN ;
			while (size--) {
				TreeNode* temp = que.front();
				que.pop();
				max_value = max(max_value, temp->val);
				if (temp->left) que.push(temp->left);
				if (temp->right) que.push(temp->right);
			}
			res.push_back(max_value);
		}
		return res; 
	}
};


