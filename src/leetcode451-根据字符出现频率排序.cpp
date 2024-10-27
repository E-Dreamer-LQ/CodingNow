// leetcode451-根据字符出现频率排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/sort-characters-by-frequency/

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


typedef pair<char, int> IIPair;

class Solution {
public:
	//bool cmp (int left,int right){
	//		return left > right;
	//};
	string frequencySort(string s) {
		string res = "";
		unordered_map <char, int> hashmap;
		for (auto str : s) {
			hashmap[str]++;
		}
		// 拷贝到vec 中进行排序处理
		vector<pair<char, int>> vec(hashmap.begin(), hashmap.end());
		sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
			return a.second > b.second;
			});
		for (auto it : vec) {   // vec 是 <char,int> 成对存在的vector向量
			while (it.second--) {
				res.push_back(it.first);
			}
		}
		return res;
	}
};


void main() {
	Solution s;
	string str = "tree";
	string res = s.frequencySort(str);
	cout << res << endl;
}