// leetcode5-最长回文子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/longest-palindromic-substring/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-bao-gu/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std; 

// 暴力法是基础，动态规划是必须掌握，中心扩散要会写
// 方法1 ： 暴力法: 超时
class Solution {
public:
	bool isPalindrome(string s,int left,int right) {
		// 验证子串s[left, right] 是否为回文串
		while (left < right) {
			if (s[left] != s[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true; 
	}
	string longestPalindrome(string s) {
		int size = s.size();
		if (size < 2) return s;
		int max_len = 1;
		string res = s.substr(0, 1);
		// 枚举所有长度大于等于2的子串
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (j - i + 1 > max_len&& isPalindrome(s, i, j)) {
					max_len = j - i + 1;
					res = s.substr(i, max_len);
				}
			}
		}
		return res;
	}
};


// 方法二： 最长公共子串

class Solution2
{
public:
	string longestPalindrome(string s)
	{
		//判断空字符串的情况
		if (s == "")
		{
			return "";
		}
		string result("");
		int sSize = int(s.size());
		string reverseS = s;
		reverse(reverseS.begin(), reverseS.end());
		vector<int> tmpVec(sSize, 0);
		vector<vector<int>> store(sSize, tmpVec);
		int maxLength = 0, end = 0;

		for (int i = 0; i < sSize; i++)
		{
			for (int j = 0; j < sSize; j++)
			{
				if (s[i] == reverseS[j])
				{
					//动态规划
					if (i == 0 || j == 0)
					{
						store[i][j] = 1;
					}
					else
					{
						store[i][j] = store[i - 1][j - 1] + 1;
					}
				}
				if (store[i][j] > maxLength)
				{
					//判断比较的字符串是不是来源自同一个字符串
					int preJ = sSize - 1 - j;
					int nowJ = preJ + store[i][j] - 1;
					if (nowJ == i)
					{
						end = i;
						maxLength = store[i][j];
					}
				}
			}
		}

		result = s.substr(end + 1 - maxLength, maxLength);
		return result;
	}
};

// 反转字符串法优化
class Solution22
{
public:
	string longestPalindrome(string s)
	{
		//判断空字符串的情况
		if (s == "")
		{
			return "";
		}
		string result("");
		int sSize = int(s.size());
		string reverseS = s;
		reverse(reverseS.begin(), reverseS.end());
		vector<int> dp(sSize, 0);
		int maxLength = 0, end = 0;

		for (int i = 0; i < sSize; i++)
		{
			for (int j = sSize - 1; j >= 0; j--)
			{
				if (s[i] == reverseS[j])
				{
					//动态规划
					if (i == 0 || j == 0)
					{
						dp[j] = 1;
					}
					else
					{
						dp[j] = dp[j - 1] + 1;
					}
				}
				else
				{
					dp[j] = 0;
				}
				if (dp[j] > maxLength)
				{
					//判断比较的字符串是不是来源自同一个字符串
					int preJ = sSize - 1 - j;
					int nowJ = preJ + dp[j] - 1;
					if (nowJ == i)
					{
						end = i;
						maxLength = dp[j];
					}
				}
			}
		}

		result = s.substr(end + 1 - maxLength, maxLength);
		return result;
	}
};

// 方法三： 动态规划

class Solution3 {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//回文串起始位置
		int max = 1;//回文串最大长度
		vector<vector<int>>  dp(len, vector<int>(len));//定义二维动态数组 , dp[i][j] 代表 子串s[i:j]是回文串
		for (int i = 0; i < len; i++)//初始化状态
		{
			dp[i][i] = 1;
			if (i < len - 1 && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				max = 2;
				start = i;
			}
		}
		for (int length = 3; length <= len; length++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
		{
			for (int i = 0; i + length - 1 < len; i++)
			{
				int j = length + i - 1;//终止字符位置
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//dp[i][j]=dp[i+1][j-1]&&(s[i]==s[j])去除两端之间的子串是回文子串，且两端相等
				{
					dp[i][j] = 1;
					start = i;`
					max = length;
				}
			}
		}
		return s.substr(start, max);//获取最长回文子串
	}
};

// 方法四: manacher 算法。 马拉车算法

// 方法五； 中心扩散法
/*
1、如果传入重合的索引编码，进行中心扩散，此时得到的回文子串的长度是奇数；

2、如果传入相邻的索引编码，进行中心扩散，此时得到的回文子串的长度是偶数。
*/
class Solution5 {

private:

	string centerSpread(string s, int left, int right) {
		// left = right 的时候，此时回文中心是一个空隙，向两边扩散得到的回文子串的长度是奇数
		// right = left + 1 的时候，此时回文中心是一个字符，向两边扩散得到的回文子串的长度是偶数
		int size = s.size();
		int i = left;
		int j = right;
		while (i >= 0 && j < size) {
			if (s[i] == s[j]) {
				i--;
				j++;
			}
			else {
				break;
			}
		}
		// 这里要小心，跳出 while 循环时，恰好满足 s.charAt(i) != s.charAt(j)，因此不能取 i，不能取 j
		return s.substr(i + 1, j - i - 1);
	}
public:
	string longestPalindrome(string s) {
		// 特判
		int size = s.size();
		if (size < 2) {
			return s;
		}

		int maxLen = 1;
		string res = s.substr(0, 1);

		// 中心位置枚举到 len - 2 即可
		for (int i = 0; i < size - 1; i++) {
			string oddStr = centerSpread(s, i, i);
			string evenStr = centerSpread(s, i, i + 1);
			string maxLenStr = oddStr.size() > evenStr.size() ? oddStr : evenStr;
			if (maxLenStr.length() > maxLen) {
				maxLen = maxLenStr.size();
				res = maxLenStr;
			}
		}
		return res;
	}
};

void main() {
	Solution333 S;
	string s = "cbbd";
	string s2 = "babad";
	string res = S.longestPalindrome(s);
	for (auto str : res) {
		cout << str; 
	}
	cout << endl;
	string res2 = S.longestPalindrome(s2);
	for (auto str2 : res2) {
		cout << str2; 
	}

}





