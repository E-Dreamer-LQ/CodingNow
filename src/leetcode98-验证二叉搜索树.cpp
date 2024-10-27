// leetcode98-验证二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/validate-binary-search-tree

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 ///  自己
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return dfs(root);
	}
	bool dfs(TreeNode* root) {
		if (root == nullptr) return false;
		if (root->left->val < root->val && root->right->val > root->val) {
			return true;
		}
		return dfs(root->left) && dfs(root->right);
	}
};

// 别人
typedef long long ll;
bool isValidBST(TreeNode* root) {
	return dfs(root, LLONG_MIN, LLONG_MAX);
}

bool dfs(TreeNode* rt, ll minv, ll maxv) {
	if (!rt) return true;
	if (rt->val < maxv && rt->val > minv
		&& dfs(rt->left, minv, rt->val)
		&& dfs(rt->right, rt->val, maxv)) return true;
	return false;
}

// 中序遍历解法,复习中序遍历
vector<int> In(TreeNode* root) {
	vector<int> res;
	if (root == nullptr) return res;
	stack<TreeNode*> sta;
	TreeNode* cur = root;
	while (cur || !sta.empty()) {
		if (cur != nullptr) {
			sta.push(cur->left);
			cur = cur->left;
		}
		else {
			cur = sta.top();
			sta.pop();  // 访问完根节点后就可以出栈，左孩子和根节点都访问完
			res.push_back(cur->val);
			// 最后右孩子
			cur = cur->right;
		}
	}
}

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> sta;
		TreeNode* pre = nullptr;
		TreeNode* cur = root;
		while (cur != nullptr || !sta.empty()) {
			if (cur != nullptr) {
				sta.push(cur);
				cur = cur->left;
			}
			else {
				cur = sta.top();
				sta.pop();
				if (pre && (pre->val >= cur->val)) {
					return false;
				}
				pre = cur;
				cur = cur->right;
			}
		}
		return true;
	}
};

