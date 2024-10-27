// leetcode1122-数组的相对排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/relative-sort-array/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		map <int, int> p;
		vector <int> res;
		vector <int> left;
		for (auto num : arr1) {
			arr1[num]++;
		}
		for (auto i : arr2) {    // arr1,arr2 中都含有的元素
			if (p.count(i)) {
				while (p[i] > 0) {
					res.push_back(i);
					p[i]--;
				}
			}
		}
		for (auto j : arr1){    // arr1 中有， arr2 中没有的元素
			if(p.count[j] != 0){
				left.push_back[j];
				p[j] -= 1;
			}
		}
		sort(left.begin(), left.end());
		for (auto i : left) {
			res.push_back(i);
		}
	}
};