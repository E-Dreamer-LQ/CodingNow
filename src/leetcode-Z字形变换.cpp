// leetcode-Z字形变换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std; 

// 方法一： 按行排序
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows < 2) return s;
		vector<string> str(min(numRows, int(s.size()))); // 表示Z字形图案非空行
		int cur_row = 0, flag = -1;
		for (auto c : s) {
			str[cur_row] += c;
			if (cur_row == 0 || cur_row == numRows-1) {
				flag = -flag;
			}
			cur_row += flag;   // 是否下一行打印
		}
		string res = "";
		for (auto s1 : str) {
			res += s1;
		}
		return res; 
	}
};

class Solution2 {
public:
	string convert(string s, int numRows) {
		vector<string> temp(numRows);
		string res;
		if (s.empty() || numRows < 1) return res;
		if (numRows == 1) return s;
		for (int i = 0; i < s.size(); i++) {
			int ans = i / (numRows - 1);
			int cur = i % (numRows - 1);
			if (ans % 2 == 0) {  //结果为偶数或0
				temp[cur].push_back(s[i]); //按余数正序保存
			}
			if (ans % 2 != 0) {  //结果为奇数
				temp[numRows - cur - 1].push_back(s[i]); //按余数倒序保存
			}
		}
		for (int i = 0; i < temp.size(); i++) {
			res += temp[i];
		}
		return res;
	}
};

void main() {
	Solution S;
	string s = "LEETCODEISHIRING";
	int numRows = 3;
	string res = S.convert(s, numRows);
	for (auto s1 : res) {
		cout << s1;
	}
}
