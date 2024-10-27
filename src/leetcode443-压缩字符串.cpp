// leetcode443-压缩字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/string-compression/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
	int compress(vector<char>& chars) {
		map<char, int> rb_map;
		for (auto s : chars) {
			rb_map[s]++;
		}
		vector<char> temp;
		for (auto it = rb_map.begin(); it != rb_map.end(); it++) {
			temp.push_back(it->first);
			temp.push_back('0' + it->second);
		}
		return temp.size();

	}
};

void main() {
	Solution S;
	vector<char> nums{'a','b','b','b' };
	int res = S.compress(nums);
	cout << res << endl;
}