// leetcode958-二叉树的完全性检验（完全二叉树）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree

#include <iostream>
#include <queue>
using namespace std; 


// definition of TreeNode
struct TreeNode 
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL),right(NULL){}
}; 

// 使用层序遍历,层序遍历，设置一个停止标志，遇到空节点，停止标志为真，如果停止标志为真，再遍历遇到非空节点，则非完全二叉树。
class Solution {
public:
	bool isCompleteTree(TreeNode* root) {
		queue <TreeNode* > que;
		bool flag = false;
		if (root == nullptr) return false;
		que.push(root);
		while (!que.empty()) {
			TreeNode* temp = que.front();
			que.pop();
			if (temp == nullptr) flag = true;
			if (flag && temp) return false;  // 遇到nullptr，后面都应该是nullptr  
			if (temp) {   // 与层次遍历不同，只需要判断tmp是否为nullptr
				que.push(temp->left);
				que.push(temp->right);
			}
		}
	}
};

class Solution2 {
public:
	bool isCompleteTree(TreeNode* root) {
		if (!root) return true;
		queue<TreeNode*>Q;
		Q.push(root);
		bool isNull = false;
		while (!Q.empty())
		{
			int size = Q.size();
			while(size--)
			{
				TreeNode* front = Q.front();
				Q.pop();
				if (front->left)
				{
					if (isNull) return false;
					Q.push(front->left);
				}
				else isNull = true;   // 遇到nullptr ， 标志置为true
				if (front->right)
				{
					if (isNull) return false;
					Q.push(front->right);
				}
				else isNull = true;
			}
		}
		return true;
	}
};