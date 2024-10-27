// leetcode508-出现次数最多的子树元素和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/most-frequent-subtree-sum/

#include <iostream>
#include <vector>
#include <unordered_map>
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
	 vector<int> findFrequentTreeSum(TreeNode* root) {
		 unordered_map<int, int> map;
		 int max_count = 0;
		 DFS(root, map, max_count);
		 vector<int> res;
		 for (auto item : map) {
			 if (item.second == max_count) {
				 res.push_back(item.first);
			 }
		 }
		 return res;

	 }

	 int DFS(TreeNode* root, unordered_map<int, int>& map, int& max_count) {
		 if (!root) return 0;
		 int leftCount = DFS(root->left, map, max_count);
		 int rightCount = DFS(root->right, map, max_count);
		 int sum = leftCount + rightCount + root->val;
		 max_count = max(max_count, ++map[sum]); // 更新最大数量
		 return sum;
	 }
 };