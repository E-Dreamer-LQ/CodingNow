// newcoder-二叉树中和为某一值的路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	vector<vector<int> > res;
	vector<int> temp;
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return res;
		temp.push_back(root->val);
		if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL) // 到最后一个叶节点
		{
			res.push_back(temp);
		}
		FindPath(root->left, expectNumber - root->val);
		FindPath(root->right, expectNumber - root->val);
		if (temp.size() != 0)
			temp.pop_back();
		//删除temp的最后一个元素，它表示当前叶节点和根节点形成的路径不满足条件，删除叶节点，返回它的父节点
		return res;
	}
};


