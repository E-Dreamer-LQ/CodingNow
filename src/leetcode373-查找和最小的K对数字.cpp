// leetcode373-查找和最小的K对数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
 
// 方法一： 暴力法
class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<vector<int>> res; 
		vector<int> temp; 
		for (auto num1 : nums1) {
			for (auto num2 : nums2) {
				temp.push_back(num1);
				temp.push_back(num2);
				res.push_back(temp);
			}
		}
		auto cmp = [](const vector<int>& a, const vector<int>& b) {
			return a[0] + a[1] <= b[0] + b[1];
		};
		sort(res.begin(), res.end(), cmp);
		vector<vector<int>> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(res[i]);
		}
		return ans; 
	}
};

// 方法二： 使用最小堆
class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
			return a.first + a.second < b.first + b.second;
		};
		priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)>  max_heap(cmp); //  这里不能单纯的建立大根堆
		vector<vector<int>> res; 

		for (auto num1 : nums1) {
			for (auto num2 : nums2) {
				if (max_heap.size() < k) {
					max_heap.push({ num1, num2 });
				}
				else if (num1 + num2 < max_heap.top().first + max_heap.top().second) {
					max_heap.pop();
					max_heap.push({ num1,num2 });
				}
			}
		}
		// 从最大堆中提取元素
		while (!max_heap.empty()) {
			auto temp = max_heap.top();
			res.push_back({temp.first,temp.second});
			max_heap.pop();
		}
		return res;


	}
};