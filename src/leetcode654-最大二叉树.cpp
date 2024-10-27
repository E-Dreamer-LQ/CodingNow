// leetcode654-最大二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/maximum-binary-tree

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // 分治法  （难点： 1.如何知道vector数组的最大值所在位置 2 ,如何通过位置建立两个子树）
class Solution {
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return constuct(nums.begin(), nums.end());
	}
	TreeNode* constuct(vector<int>::iterator l, vector<int>::iterator r) {
		if (l == r) return nullptr;
		auto it = max_element(l, r); // 最大元素的位置
		// 建立二叉树 ，这里只需要返回根节点
		TreeNode* tn = new TreeNode(*it);
		tn->left = constuct(l, it); // 左子树
		tn->right = constuct(it + 1, r); // 右子树
		return tn;
	}
};

