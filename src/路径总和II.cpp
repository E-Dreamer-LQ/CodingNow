// 路径总和II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 


// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  class Solution {
  public:
	  vector<vector<int> > res;
	  vector<int> temp;
	  vector<vector<int> > pathSum(TreeNode* root, int sum) {
		  if (root == NULL)
			  return res;
		  temp.push_back(root->val);
		  if ((sum - root->val) == 0 && root->left == NULL && root->right == NULL)
		  {
			  res.push_back(temp);
		  }
		  pathSum(root->left, sum - root->val);
		  pathSum(root->right, sum - root->val);
		  if (temp.size() != 0)
			  temp.pop_back();
		  //删除temp的最后一个元素，它表示当前叶节点和根节点形成的路径不满足条件，删除叶节点，返回它的父节点
		  return res;
	  }
  };


  class Solution {
  public:
	  vector<vector<int>>res;
	  void search(TreeNode* root, int sum, vector<int>& temp)             // 这里引用，只用了一个temp，既然深搜了，所以要用到这个技巧
	  {
		  if (!root) return;
		  temp.push_back(root->val);
		  if (!(root->left) && !(root->right))
		  {
			  if (sum == root->val) res.push_back(temp);
		  }
		  search(root->left, sum - root->val, temp);
		  search(root->right, sum - root->val, temp);
		  temp.pop_back();                                                    // 回溯
	  }

	  vector<vector<int>> pathSum(TreeNode* root, int sum) {
		  vector<int> temp;
		  search(root, sum, temp);
		  return res;
	  }
  };