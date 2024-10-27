// newcoder-树的子结构.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
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
	// 判断是不是子结构 => 遍历后是不是子序列
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == nullptr || pRoot1 == nullptr) return false;
		return (dfs(pRoot1, pRoot2) || dfs(pRoot1->left, pRoot2) || dfs(pRoot1->right, pRoot2));   // 如果从根节点找不到就从根节点的左右儿子去找
	}

	bool dfs(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == nullptr) {
			return true;
		}
		if (pRoot1 == nullptr) {
			return false;
		}
		if (pRoot1->val != pRoot2->val) {
			return false; 
		}
		return dfs(pRoot1->left, pRoot2->left) && dfs(pRoot1->right, pRoot2->right);
	}
};



