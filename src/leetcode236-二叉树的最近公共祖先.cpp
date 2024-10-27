// leetcode236-二叉树的最近公共祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
// 最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）


#include <iostream>
#include <stack>
using namespace std; 



// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // 方法一: p,q如果分别在左右孩子， 则公共祖先就是root ， 如果p，q如果都在左孩子，则公共祖先在左孩子， 如果p,q都在右孩子，则公共祖先在右孩子
 /*递归遍历左右子树，如果左右子树查到节点都不为空，则表明p和q分别在左右子树中，因此，当前节点即为最近公共祖先；如果左右子树其中一个不为空，则返回非空节点。 */
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || (p == root && q == root)) return root;
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		return  left == nullptr ? right : (right == nullptr ? left : root);
	}
};


// 方法二：递归，中序遍历(递归)，对每个节点，计算其左子树和右子树包含的p或q个数，并返回。第一个包含2个目标值的子树对应的根节点就是最低公共祖先

class Solution2 {
public:
	TreeNode* res = nullptr; // 初始值 
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int dummy = find(root, p,q);
		return res;
	}

	int find(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) return 0;
		int mid = 0;
		if (root == p || root == q) mid = 1;
		int left = find(root->left, p, q); // 搜索左子树
		if (left + mid == 2) { // 提前剪枝，避免不必要计算
			if (res!=nullptr) {
				res = root;
				return 2;
			}
		}
		int right = find(root->right, p, q); // 搜索右子树
		if (left + right + mid == 2) {
			if (res != nullptr) {
				res = root;
			}
		}
		return left + right + mid;
	}
};




