// newcoder-左旋转字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <queue>
using namespace std; 
class Solution {
public:
	string LeftRotateString(string str, int n) {
		queue<char> que;
		for (int i = 0; i < n; i++) {
			que.push(str[i]);
		}

		string res = str.erase(0, n);
		while (!que.empty()) {
			res += que.front();
			que.pop();
		}
		return res; 
	}
};

void main() {
	Solution S;
	string str = "abcdefg";
	int n = 2;
	string res = S.LeftRotateString(str, n);
	for (auto ss : res) {
		cout << ss;
	}

}


