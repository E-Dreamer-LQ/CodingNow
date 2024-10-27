// leetcode94-二叉树的中序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//   中序遍历 ： 先左子树 -》 根节点  -》 右子树
//   https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/die-dai-fa-by-jason-2/

#include <iostream>
#include <vector>
#include <stack>

using namespace std; 
/**
 * Definition for a binary tree node.
 * struct treenode {
 *     int val;
 *     treenode *left;
 *     treenode *right;
 *     treenode(int x) : val(x), left(null), right(null) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack <TreeNode*> sta;
		vector <int> res;
		if (root == nullptr) return res;  // 空树， 直接返回res
		TreeNode* cur = root;
		while (cur != nullptr || !sta.empty) {
			// 先遍历左孩子
			if (cur != nullptr ){
				sta.push(cur);
				cur = cur->left;
			}
			else {
				// 再 是 根结点
				cur = sta.top(); 
				sta.pop();  // 访问完根节点后就可以出栈，左孩子和根节点都访问完
				res.push_back(cur->val);
				// 最后右孩子
				cur = cur->right;
			}
		}
		return res; 
	}
};


// 其他方法 （颜色标记法）


