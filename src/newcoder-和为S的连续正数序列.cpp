// newcoder-和为S的连续正数序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include <iostream>
#include<vector>
using namespace std;

// 双指针法（滑动窗口）
/*
两个窗口都是从左边出发，不是两边夹逼。另外，当小于目标数时high++；
大于目标数时low++，如果是high--，那么你仔细想想，你的窗口还怎么往后移动，
整个结果在第一次大于目标数之后就不会往后移动，
相反，而是在在这个low和high之间夹逼试探，最终啥都找不到或者只能找到一个。
*/

class Solution {
public:
	vector<vector<int>> FindContinuousSequence(int sum) {
		vector<vector<int>> res; 
		int low = 1;
		int high = 2;
		while (low < high) {   // 这里不能等
			//由于是连续的，差为1的一个序列，那么求和公式是(a0+an)*n/2
			int cur = (high + low) * (high - low + 1) / 2;
			if (cur == sum) {
				vector<int> temp; 
				for (int i = low; i <= high; i++) {
					temp.push_back(i);
				}
				res.push_back(temp); 
				low++;
			}
			//如果当前窗口内的值之和小于sum，那么右边窗口右移一下
			else if (cur < sum) {
				high++; 
			}
			else {  //如果当前窗口内的值之和大于sum，那么左边窗口右移一下
				low++; 
			}
		}
		return res; 
	}
};

// 方法二： 
class Solution2 {
public:
	vector<vector<int>> FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		for (int n = sqrt(2 * sum); n >= 2; n--) {
			if ((n & 1) == 1 && sum % n == 0 || (sum % n) * 2 == n) {
				vector<int> temp; 
				for (int j = 0, k = (sum / n) - (n - 1) / 2; j < n; j++, k++) {
					temp.push_back(k);
				}
				res.push_back(temp); 
			}
		}
		return res; 
	}
};