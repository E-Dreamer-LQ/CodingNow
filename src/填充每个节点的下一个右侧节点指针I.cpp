// 填充每个节点的下一个右侧节点指针I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<queue>
using namespace std; 

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

/*第二种情况是连接不同父节点之间子节点的情况。更具体地说，
连接的是第一个父节点的右孩子和第二父节点的左孩子。
由于已经在父节点这一层建立了 next 指针，
因此可以直接通过第一个父节点的 next 指针找到第二个父节点，
然后在它们的孩子之间建立连接。*/
class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr || root->left == nullptr) return nullptr;
		root->left->next = root->right;  // 连接同父节点的左右两个节点
		if (root->next) {
			root->right->next = root->next->left;   // 连接不同父节点的两个节点
		}
		connect(root->left);
		connect(root->right);
		return root;
	}
};

// 方法二： 层序遍历
class Solution {
public:
	Node* connect(Node* root) {
		if (!root)return root;
		queue<Node*> q;
		q.push(root); 
		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				Node* t = q.front();
				q.pop();
				if (i != n - 1) {
					Node* tNext = q.front();
					t->next = tNext;
				}
				if (t->left)q.push(t->left);
				if (t->right)q.push(t->right);
			}
		}
		return root;
	}
};