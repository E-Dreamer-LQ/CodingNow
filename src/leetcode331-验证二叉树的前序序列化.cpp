// leetcode331-验证二叉树的前序序列化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/

#include <iostream>
#include <string>
using namespace std; 

/*
这道题目可以通过二叉树的性质来解，对于一棵二叉树，其叶子节点的数量是非叶子节点数量 + 1。因此我们初始化degree = 1，
每次遇到叶子结点就减1，遇到其他非叶子节点就加1，判断degree最后是否为零即可

*/
// 方法一： 通过二叉树性质， 非叶子节点 比 叶子节点 少一
class Solution {
public:
	bool isValidSerialization(string preorder) {
		if (preorder == "#") return true;
		int degree = 1;
		int n = preorder.size();
		for (int i = 0; i < n; i++) {
			if (degree == 0) return false;
			if (preorder[i] == ',') continue;
			if (preorder[i] == '#') {
				degree = degree - 1;
			}
			else {
				while (i < n && preorder[i] != ',') i++;
				degree += 1;
			}
		}

	}
};

/*
根结点的入度为0出度为2，其他非叶子结点的入度为1出度为2，叶子节点入度为1出度为0。
因为根节点多出来一个出度，所以初始化度为1，一个非叶子节点时度 + 1，加入一个空节点（叶子节点）时度 - 1，
如果度为0，即达到出度入度相等，已经形成一颗二叉树
*/