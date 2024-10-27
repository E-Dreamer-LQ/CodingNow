// newcoder-二叉树的下一个结点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std; 


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

//分析二叉树的下一个节点，一共有以下情况：
//1.二叉树为空，则返回空；
//2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
//3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		//如何结点为空，，返回空
		if (pNode == nullptr) return nullptr; 
		// 如何结点的右孩子存在
		if (pNode->right != nullptr) {
			pNode = pNode->right;
			while (pNode->left != nullptr) {
				pNode = pNode->left; 
			}
			return pNode; 
		}
		// 结点不是根节点
		while (pNode->next != nullptr) {
			TreeLinkNode* pRoot = pNode->next; // 当前节点的根节点
			if (pRoot->left == pNode) {  // 如果该结点是其父节点的左孩子
				return pRoot; 
			}
			pNode = pNode->next; 
		}
		return nullptr; 

	}
};