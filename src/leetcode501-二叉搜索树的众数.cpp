// leetcode501-二叉搜索树的众数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/

#include <iostream>
#include <vector>
using namespace std;

/*
假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
*/

 // Definition for a binary tree node.
 struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 /*
 二叉搜索树的中序遍历是一个升序序列，逐个比对当前结点(root)值与前驱结点（pre)值。
 更新当前节点值出现次数(curTimes)及最大出现次数(maxTimes)，更新规则：若curTimes=maxTimes,
 将root->val添加到结果向量(res)中；若curTimes>maxTimes,清空res,
 将root->val添加到res,并更新maxTimes为curTimes  (求递增数组众数)
 */
class Solution {
public:
	void inOrder(TreeNode* root, TreeNode*& pre, int& curTimes,
		int& maxTimes, vector<int>& res) {
		if (!root) return;
		inOrder(root->left, pre, curTimes, maxTimes, res); // 左子树
		//判断当前值与上一个值的关系,
		if (pre)
			curTimes = (root->val == pre->val) ? curTimes + 1 : 1;
		//判断当前数量与最大数量的关系
		if (curTimes == maxTimes)
			res.push_back(root->val);
		else if (curTimes > maxTimes) {
			res.clear(); // 前面保存众数的就清空
			res.push_back(root->val);
			maxTimes = curTimes;
		}
		pre = root;
		inOrder(root->right, pre, curTimes, maxTimes, res); // 右子树
	} 
	vector<int> findMode(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		TreeNode* pre = NULL;
		int curTimes = 1, maxTimes = 0;
		inOrder(root, pre, curTimes, maxTimes, res);
		return res;
	}
};