// leetcode392-判断子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/is-subsequence

#include <iostream>
#include<string> 
#include <stack>
using namespace std; 


//方法一： 双指针
class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s == "") return true;
		int c1 = 0, c2 = 0;
		while (c1 < s.size() && c2 < t.size()) {
			if (s[c1] == t[c2]) {
				c1++;
				c2++;
			}
			else {
				c2++;
			}
		}
		return c1 == s.length();
	}
};


// 方法二: 使用栈结构
class Solution2 {
public:
	bool isSubsequence(string s, string t) {
		if (s == "") return false;
		stack<char> sta1;
		stack<char> sta2;
		for (int i = 0; i < s.size(); i++) {
			sta1.push(s[i]);
		}
		for (int j = 0; j < t.size(); j++) {
			sta2.push(t[j]);
		}
		while (!sta2.empty()) {
			if (sta1.top() == sta2.top()) {
				sta1.pop();
				sta2.pop();
			}
			else {
				sta2.pop();
			}
		}
		return sta1.empty();
	}
};

void main() {
	Solution S1;
	Solution2 S2;
	string s = "axc";
	string t = "ahbgdc";
	cout << boolalpha << S1.isSubsequence(s, t) << endl; 
	cout << boolalpha << S2.isSubsequence(s, t) << endl;
}

