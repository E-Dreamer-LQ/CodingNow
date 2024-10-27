// leetcode173-二叉搜索树迭代器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 



/*
BSTIterator构造方法功能：保存最左边的一条路径，找最小节点。具体：迭代循环遍历左子树，依次保存到数组中。最终存放整棵树最左边的节点，即最小值。
next方法功能（中序遍历）：找出当前最小值，准备好下一个最小值。具体：先取出最小值。然后以最小值为起点，中序遍历，对于存在右子树的情况，在右子树中迭代循环遍历左子树，依次保存到数组中，直到最左边的节点。返回最先取出的最小值
hasNext方法：判断数组是否为空，不为空则返回true，为空则返回false*/
struct  TreeNode
{
	int val;
	TreeNode* left; 
	TreeNode* right;
	TreeNode (int x) : val(x), left(nullptr), right(nullptr) {}
};
class BSTIterator {
private:
	vector<TreeNode*> S;
public:
	BSTIterator(TreeNode* root) {
		while (root) {
			S.push_back(root);
			root = root->left;
		}
	}
	int next() { //找出当前最小值，准备好下一个最小值
		TreeNode* t = S.back();
		S.pop_back();
		int val = t->val;
		t = t->right;
		while (t) {
			S.push_back(t);
			t = t->left;
		}
		return val;
	}
	bool hasNext() {
		return !S.empty();
	}
};