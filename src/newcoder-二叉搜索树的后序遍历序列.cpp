 // newcoder-二叉搜索树的后序遍历序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
	// 二叉搜索树：左孩子 < 根  ， 右孩子 > 根
	// 中序遍历是一个递增的序列
	bool VerifySquenceOfBST(vector<int> sequence) {
		int size = sequence.size();
		return judge(sequence, 0, size - 1);
	}
	bool judge(vector<int> sequence, int start, int end) {
		int root = sequence[end];
		if (sequence.empty() || start > end) return false;
		int i = start;  
		for (; i < end; ++i) {   // 找到右子树这边第一个大于root的节点
			if (sequence[i] > root) {
				break; 
			}
		}
		for (int j = i; j < end; ++j) {  // 右子树这边
			if (sequence[j] < root) {
				return false; 
			}
		}
		bool left = true; 
		if (i > start) {
			left = judge(sequence, start, i - 1);   // 左子树这边也要满足bst
		}
		bool right = true;
		if (i < end-1) {         // 右子树这边满足bst
			right = judge(sequence, i, end-1);
		}
		return left && right; 
	}
};


// 来自左神 
class Solution {
public:
	bool isPostArray(vector<int> arr) {
		if (arr.size() == 0) return false; 
		return isPost(arr, 0, arr.size() - 1); 
	}
	bool isPost(vector<int> arr, int start, int end) {
		if (start == end) return true; 
		int less_right = -1; 
		int more_left = end; 
		for (int i = start; i < end; i++) {
			if (arr[end] > arr[i]) {
				less_right = i; 
			}
			else {
				more_left = more_left == end ? i : more_left; // more_left 是否更新过
			}
		}

		if (less_right == -1 || more_left == end) {  // 该二叉搜索树 只有 左树  或者只有  右树
			return isPost(arr, start, end-1);  // 看 arr[start,end-1] 是否满足
		}
		if (less_right != more_left-1) {
			return false; 
		}
		return isPost(arr, start, less_right) && isPost(arr,more_left, end - 1); 
	}
};