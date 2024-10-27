// leetcode524-通过删除字母匹配到字典里最长的单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		string res = "";
		bool flag; 
		for (auto str : d) {
			for (int i = 0; i < str.size(); i++) {
				if (s.find(str[i]) != s.npos) {
					flag = true; 
					continue;
				}
				else {
					flag = false; 
					break; 
				}
			}
			if (flag && str.size() >= res.size()) {
				if (str.size() == res.size()) {
					if (str < res) {
						res.clear();
						res += str;
					}
				}
				else {
					res.clear();
					res += str;
				}

			}
		}
		return res; 
	}
};


void main() {;
	Solution S;
	string s = "bab";
	vector<string> d{"ba","ab","a","b"};
	string res = S.findLongestWord(s, d);
	cout << res << endl;

}

// ？？？？？？？ 测试有问题

// 来自别人
class Solution2 {
public:
	string findLongestWord(string s, vector<string>& d) {
		vector<string> tmp;
		int maxIdx = 0;
		for (int i = 0; i < d.size(); i++) {
			if (isSubString(s, d[i])) {
				tmp.push_back(d[i]);
			}
		}
		if (tmp.empty())  return "";
		auto cmp = [](const string& a, const string& b) {
			if (a.length() == b.length()) {
				return a < b;
			}
			else {
				return a.length() > b.length();
			}
		};
		sort(tmp.begin(), tmp.end(), cmp);
		return tmp[0];
	}
private:
	bool isSubString(string a, string b) {
		int i = 0, j = 0;
		while (i < a.length() && j < b.length()) {
			if (a[i] == b[j]) {
				i++; j++;
			}
			else {
				i++;
			}
		}
		if (j == b.length()) return true;
		else return false;
	}
};