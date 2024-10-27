// newcoder-序列化二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stack>
#include <string>
using namespace std; 


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:

private:
	TreeNode* decode(char*& str) {
		if (*str == '#') {
			str++;
			return NULL;
		}
		int num = 0;
		while (*str != ',')
			num = num * 10 + (*(str++) - '0');
		str++;
		TreeNode* root = new TreeNode(num);
		root->left = decode(str);
		root->right = decode(str);
		return root;
	}
public:
	char* Serialize(TreeNode* root) {
		if (!root) return "#";
		string r = to_string(root->val);
		r.push_back(',');
		char* left = Serialize(root->left);   // 前序遍历
		char* right = Serialize(root->right);
		char* ret = new char[strlen(left) + strlen(right) + r.size()];
		strcpy(ret, r.c_str());  // c_str: 一个指向正规C字符串的指针, 内容与本string串相同
		strcat(ret, left); // 字符串的拼接
		strcat(ret, right);
		return ret;
	}
	TreeNode* Deserialize(char* str) {
		return decode(str);
	}
};


