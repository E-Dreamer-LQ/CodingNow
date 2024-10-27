// 不同的二叉搜索树II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
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
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		if (n == 0) return res;
		return getAns(1, n);
	}

	vector<TreeNode*> getAns(int start, int end) {
		vector<TreeNode*> ans;
		if (start > end) {
			ans.push_back(nullptr);
			return ans;
		}
		// 只有一个数字，当前数字作为一棵树加入到结果
		if (start == end) {
			TreeNode* tree = new TreeNode(start);
			ans.push_back(tree);
			return ans;
		}
		// 尝试每个数字作为根节点
		for (int i = start; i <= end; i++) {
			//得到所有可能的左子树
			vector<TreeNode*> leftTrees = getAns(start, i - 1);
			vector<TreeNode*> rightTrees = getAns(i + 1, end);
			//左右子树两两组合
			for (auto left : leftTrees) {
				for (auto right : rightTrees) {
					TreeNode* root = new TreeNode(i);
					root->left = left;
					root->right = right;
					// 加入到最终结果
					ans.push_back(root);
				}
			}
		}
		return ans;
	}
};

/*
对于连续整数序列[start, end]中的一点i，若要生成以i为根节点的BST，则有如下规律：

i左边的序列可以作为左子树结点，且左儿子可能有多个，所以有vector<TreeNode *> leftTrees = generate(left, i - 1);；
i右边的序列可以作为右子树结点，同上所以有vector<TreeNode *> rightTrees = generate(i + 1, right);；
产生的以当前i为根结点的BST（子）树有leftTrees.size() * rightTrees.size()个，遍历每种情况，即可生成以i为根节点的BST序列；
然后以for循环使得[start, end]中每个结点都能生成子树序列。

*/