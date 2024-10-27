// leetcode145-二叉树的后序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
//  后序遍历： 左孩子 -》 右孩子   -》 根节点

#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 前序变后序 ： https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/liang-chong-jie-fa-by-jason-2-26/
class Solution {    
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack <TreeNode*> sta;
		vector<int> res;
		if (root != nullptr) return res;
		TreeNode* temp = root;
		while (temp != nullptr || !sta.empty()) {
			while (temp) {
				// 访问结点， 左孩子入栈
				temp = temp->left;
				sta.push(temp); 
				res.push_back(temp->val);
				temp = temp->right;
			}
			// 访问完后出栈，temp从栈顶弹出
			sta.top();
			sta.pop();
		}
		// 结果序列逆序
		reverse(res.begin(), res.end());
		return res;
	}

};

// 另外一种写法
class Solution2 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack <TreeNode*> sta;
		vector<int> res;
		if (root != nullptr) return res;
		sta.push(root);
		while (!sta.empty()) {
			TreeNode* temp = sta.top();
			sta.pop();
			if (temp->left != nullptr) sta.push(temp->left);
			if (temp->right != nullptr) sta.push(temp->right);
			res.push_back(temp->val);
		}
		// 结果序列逆序
		reverse(res.begin(), res.end());
		return res;
	}
};

// 第二种方法 (重点理解)
vector<int> PostOrderLoop(TreeNode* root)
{
	stack<TreeNode*> mystack;
	vector<int> ans;
	TreeNode* curr = root;
	TreeNode* pre = NULL;

	while (curr || !mystack.empty())
	{
		while (curr)
		{
			mystack.push(curr);
			curr = curr->left;
		}
		curr = mystack.top();

		//若右节点已经访问过或者没有右节点  则输出该节点值
		if (curr->right == nullptr || pre == curr->right) {
			mystack.pop();
			ans.push_back(curr->val);
			pre = curr;
			curr = NULL;
		}
		else {
			curr = curr->right;
			pre = NULL;
		}
	}
	return ans;
}


/*  java 版本，便于理解  https://leetcode-cn.com/problems/binary-tree-postorder-traversal/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--34/
public List<Integer> inorderTraversal(TreeNode root) {
	List<Integer> ans = new ArrayList<>();
	TreeNode cur = root;
	while (cur != null) {
		//情况 1
		if (cur.left == null) {
			ans.add(cur.val);
			cur = cur.right;
		}
		else {
			//找左子树最右边的节点
			TreeNode pre = cur.left;
			while (pre.right != null && pre.right != cur) {
				pre = pre.right;
			}
			//情况 2.1   右孩子是空
			if (pre.right == null) {
				pre.right = cur;
				cur = cur.left;
			}
			//情况 2.2    右孩子已经访问过
			if (pre.right == cur) {
				pre.right = null; //这里可以恢复为 null
				ans.add(cur.val);
				cur = cur.right;
			}
		}
	}
	return ans;
}
*/