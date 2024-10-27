// leetcode530-二叉搜索树的最小绝对值差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/random-pick-with-weight/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std; 

// 二叉搜索树： 左子树小于 < 根节点 < 右子树

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // 方法一： 前序遍历
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		if (root == nullptr) return 0;
		int res = INT_MAX;
		int left_val = 0;
		int right_val = 0; 
		stack<TreeNode*> sta;
		sta.push(root);
		while (!sta.empty()) {
			TreeNode* temp = sta.top();
			sta.pop();
			if (temp->right)
			{
				sta.push(temp->right);
				right_val = abs(temp->val - temp->right->val);
				res = min(res, right_val);
			}
			if (temp->left) {
				sta.push(temp->left);
				left_val = abs(temp->val - temp->left->val);
				res = min(res, left_val);
			}

		}
		return res; 

	}
};


// 中序遍历
class Solution2  {
public:
	int getMinimumDifference(TreeNode* root) {
		int res = INT_MAX;
		findnode(root);
		for (int i = 1; i < vals.size(); i++) {
			res = min(res, abs(vals[i] - vals[i - 1]));
		}
		return res;
	}
private:
	vector<int> vals;
	void findnode(TreeNode* root) {  // 中序遍历（递归版本你最合适） 
		if (root == nullptr) return;
		findnode(root->left);
		vals.push_back(root->val);
		findnode(root->right);
	}
};




