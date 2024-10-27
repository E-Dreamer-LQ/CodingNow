// newcoder4-重建二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include <iostream>
#include <vector>
using namespace std; 

 // Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        // 重点找到: 根节点
        if (pre.size() == 0) return nullptr;
        int i=0; 
        // 找到根节点位置
        while(vin[i] != pre[0]){
            i++;
        }
        TreeNode* root = new TreeNode(pre[0]);
        vector<int> preleft(pre.begin()+1,pre.begin()+i+1);
        vector<int> preright(pre.begin()+i+1,pre.end());
        vector<int> inleft(vin.begin(),vin.begin()+i);
        vector<int> inright(vin.begin()+i+1,vin.end());
        root->left = reConstructBinaryTree(preleft,inleft);
        root->right = reConstructBinaryTree(preright,inright);
        return root; 
    }
};

