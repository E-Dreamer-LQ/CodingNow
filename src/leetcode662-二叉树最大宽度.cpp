// leetcode662-二叉树最大宽度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/maximum-width-of-binary-tree

#include <iostream>
#include <map>
#include <algorithm>
#include <deque>
using namespace std; 


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


  // 方法一: hashmap :map存该层里面最先出现的index,后来找到该层的结点与最先出现的index的差值的最大值即可。
class Solution {
public:
	int maxW;
	map<int, int> map;
	int widthOfBinaryTree(TreeNode* root) {
		dfs(root, 1, 1);
		return maxW;
	}
	void dfs(TreeNode* root, int level, int index) {
		if (root == nullptr) return;
		if (map.find(level) == map.end()) {
			map.insert(level, index);
		}
		maxW = max(maxW, index - map[level] + 1); // 有可能是上一个maxW的值更大，后来找到该层的结点与最先出现的index的差值的最大值即可
		dfs(root->left, level + 1, index * 2);
		dfs(root->right,level+1 ,index*2+1);
	}
};


// 方法二，使用层序遍历方法+ 双端队列
class Solution2 {
public:
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr) return 0;
		int res = 0;
		deque<TreeNode*> dq;
		dq.push_front(root);
		while (!dq.empty()) {
			// 出队前需要判断队列是否为空.
			while (!dq.empty() && dq.front() == nullptr) dq.pop_front();
			while  (!dq.empty() && dq.back() == nullptr) dq.pop_back();
			int n = dq.size();
			if (n == 0) break;
			res = max(res, n);
			while (n--) {
				TreeNode* temp = dq.front();
				dq.pop_front();
				dq.push_back(temp == nullptr ? nullptr : temp->left);
				dq.push_back(temp == nullptr ? nullptr : temp->right);
			}
		}
		return res;
	}

};


