// leetcode215-数组中的第K个最大元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/kth-largest-element-in-an-array

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 方法一, 堆排序
class Solution {
public:
	//void heapinsert() {
	//	return ;
	//}
	//void heapify(vector<int> nums) {
	//	return ; 
	//}
	//void swap(vector<int> nums, int i, int j) {
	//	int temp = nums[j];
	//	nums[j]= nums[i];
	//	nums[i] = temp;
	//}
	int findKthLargest(vector<int>& nums, int k) {
		vector<int> res;
		priority_queue<int, vector<int>, greater<int>> minheap; // 创建一个小跟堆
		for (auto n : nums) {  //使用auto
			if (minheap.size() == k) {
				if (n > minheap.top()) {   
					// 维护一个大小为k的小顶堆
					minheap.pop();
					minheap.push(n);
				}
			}
			else {
				minheap.push(n);
			}
		}
		return minheap.top();
	}
};

void main() {
	vector<int> nums{3,2,1,5,6,4};
	int k = 2;
	Solution S;
	int res = S.findKthLargest(nums, k);
	cout << res << endl;
}


/**利用快速排序中的partition思想解决，时间复杂度O(N); **/
