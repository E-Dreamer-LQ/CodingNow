﻿// 二叉树的最小深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std; 
/*
很多人写出的代码都不符合 1,2 这个测试用例，是因为没搞清楚题意
题目中说明:叶子节点是指没有子节点的节点，这句话的意思是 1 不是叶子节点
题目问的是到叶子节点的最短距离，所以所有返回结果为 1 当然不是这个结果
另外这道题的关键是搞清楚递归结束条件
叶子节点的定义是左孩子和右孩子都为 null 时叫做叶子节点
当 root 节点左右孩子都为空时，返回 1
当 root 节点左右孩子有一个为空时，返回不为空的孩子节点的深度
当 root 节点左右孩子都不为空时，返回左右孩子较小深度的节点值
*/

struct TreeNode
{
	int val;
	TreeNode* left; 
	TreeNode* right; 
	TreeNode(int data): val(data), left(nullptr), right(nullptr){}

};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		//这道题递归条件里分为三种情况
		//1.左孩子和有孩子都为空的情况，说明到达了叶子节点，直接返回1即可
		if (root->left == nullptr && root->right == nullptr) return 1;
		//2.如果左孩子和由孩子其中一个为空，那么需要返回比较大的那个孩子的深度        
		int m1 = minDepth(root->left);
		int m2 = minDepth(root->right);
		//这里其中一个节点为空，说明m1和m2有一个必然为0，所以可以返回m1 + m2 + 1;
		if (root->left == nullptr || root->right == nullptr) return m1 + m2 + 1;

		//3.最后一种情况，也就是左右孩子都不为空，返回最小深度+1即可
		return min(m1, m2) + 1;
	}
};


