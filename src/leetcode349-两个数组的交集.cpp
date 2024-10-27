// leetcode349-两个数组的交集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map <int,int> hash;
		for (auto num : nums1) {
			hash[num]++;
		}
		for (int i : nums2) {
			auto a = hash.find(i); // nums1 中和 nums2 中相等的元素
			if (a != hash.end()) {
				res.push_back(i);
				hash.erase(a);   // 将检索到的元素删去（去除重复）
			}
		}
		return res;
	}
};


void main() {
	Solution s;
	vector<int> nums1{1,2,2,1};
	vector<int> nums2{ 2,2 };
	vector<int> result = s.intersection(nums1, nums2);
	for (int i=0; i<result.size();i++){
		cout << result[i] << endl;
	}
}