// leetcode513-找数左下角的值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std; 

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // 方法一
class Solution {
public:
	int height(TreeNode* Node) {
		if (Node == nullptr) return 0;
		return max(height(Node->left)+1, height(Node->right)+1);
	}
	int findBottomLeftValue(TreeNode* root) {
		if (root == nullptr) return 0; 
		int max_height = height(root);
	

	}
};


// 方法二：  从右向左加入队列，最左的一定是最后访问的（层序遍历反向）
class Solution {
public:
	int findBottomLeftValue(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<TreeNode*> que;
		int res; 
		que.push(root);
		while (!que.empty) {
			int size = que.size();
			TreeNode* temp = que.front();
			res = temp->val;
			que.pop();
			if (temp->right) que.push(temp->right);
			if (temp->left) que.push(temp->left);   // 这里层序遍历是需要将该层所有节点遍历并pop掉
		}

		return res; 


	}
};
