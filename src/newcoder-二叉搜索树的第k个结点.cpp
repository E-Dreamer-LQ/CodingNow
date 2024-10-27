// newcoder-二叉搜索树的第k个结点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std; 

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		stack <TreeNode*> sta;
		vector <TreeNode*> res;
		if (pRoot == nullptr || k <0 ) return nullptr;  // 空树， 直接返回res
		TreeNode* cur = pRoot;
        int index = 0; 
		while (cur != nullptr || !sta.empty()) {
			// 先遍历左孩子
			if (cur != nullptr ){
				sta.push(cur);
				cur = cur->left;
			}
			else {
				// 再 是 根结点
				TreeNode* temp = sta.top(); 
				sta.pop();  // 访问完根节点后就可以出栈，左孩子和根节点都访问完
                index++; 
				if (index == k) return temp; 
				// 最后右孩子
				cur = temp->right;
			}
		}
		return nullptr; 
	}
};