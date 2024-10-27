// newcoder-按之字形顺序打印二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <queue>
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
	vector<vector<int>> res;
	vector<vector<int> > Print(TreeNode* pRoot) {
		queue<TreeNode*> que;
		if (pRoot == nullptr) return res;
		que.push(pRoot);
		int index = 1;
		while (!que.empty()) {
			vector<int> temp;
			int size = que.size();
			while (size--) {
				TreeNode* cur = que.front(); 
				que.pop(); 
				temp.push_back(cur->val); 
				if (cur->left != nullptr) que.push(cur->left); 
				if (cur->right != nullptr) que.push(cur->right); 
			}
			if (index % 2 == 1) {
				res.push_back(temp);
			}
			else {
				reverse(temp.begin(), temp.end());
				res.push_back(temp);
			}
			index++;
		}
		return res;
	}
};

