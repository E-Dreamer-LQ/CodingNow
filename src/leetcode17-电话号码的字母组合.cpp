// leetcode17-电话号码的字母组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	unordered_map<char, string> hashmap; 
	vector<string> res;
	string temp = "";
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return res;
		hashmap.insert(make_pair('2', "abc"));
		hashmap.insert(make_pair('3', "def"));
		hashmap.insert(make_pair('4', "ghi"));
		hashmap.insert(make_pair('5', "jkl"));
		hashmap.insert(make_pair('6', "mno"));
		hashmap.insert(make_pair('7', "pqrs"));
		hashmap.insert(make_pair('8', "tuv"));
		hashmap.insert(make_pair('9', "wxyz"));
		dfs(digits,0);
		return res; 
	}
	void dfs(string digits, int start) {
		if (temp.length() == digits.length()) { // 每个digits的元素对应string 取一个元素
			res.push_back(temp);
			return;
		}
		string str = hashmap.find(digits[start])->second;
		for (auto i : str) {
			temp += i;
			dfs(digits, start + 1);
			temp.pop_back();
		}
	}
};
// 来自别人
class Solution2 {
public:
	void backtrace(vector<string>& res, string tmp_res, string digits, int idx) {  // res为引用形式
		if (tmp_res.length() == digits.length()) {
			res.push_back(tmp_res);
			return;
		}
		string str = table[digits[idx]];
		for (auto i : str) {
			tmp_res += i;
			backtrace(res, tmp_res, digits, idx + 1);
			tmp_res.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {

		vector<string> res;
		if (digits == "")  return res;
		backtrace(res, "", digits, 0);
		return res;
	}
private:
	unordered_map<char, string> table{ {'0', " "}, {'1',"*"}, {'2', "abc"},
			{'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
			{'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
			{'9',"wxyz"} };
};
void main() {
	Solution S;
	Solution2 S2;
	string digits = "23";
	vector<string> res = S.letterCombinations(digits);
	vector<string> res2 = S2.letterCombinations(digits);
	for (auto s1 : res) {
		cout << s1;
	}
	cout << endl; 
	for (auto s2 : res2) {
		cout << s2;
	}
	cout << endl;

}