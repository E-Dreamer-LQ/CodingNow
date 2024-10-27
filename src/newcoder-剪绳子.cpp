// newcoder-剪绳子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

/**
 * 题目分析：
 * 先举几个例子，可以看出规律来。
 * 4 ： 2*2
 * 5 ： 2*3
 * 6 ： 3*3
 * 7 ： 2*2*3 或者4*3
 * 8 ： 2*3*3
 * 9 ： 3*3*3
 * 10：2*2*3*3 或者4*3*3
 * 11：2*3*3*3
 * 12：3*3*3*3
 * 13：2*2*3*3*3 或者4*3*3*3
 *
 * 下面是分析：
 * 首先判断k[0]到k[m]可能有哪些数字，实际上只可能是2或者3。
 * 当然也可能有4，但是4=2*2，我们就简单些不考虑了。
 * 5<2*3,6<3*3,比6更大的数字我们就更不用考虑了，肯定要继续分。
 * 其次看2和3的数量，2的数量肯定小于3个，为什么呢？因为2*2*2<3*3，那么题目就简单了。
 * 直接用n除以3，根据得到的余数判断是一个2还是两个2还是没有2就行了。
 * 由于题目规定m>1，所以2只能是1*1，3只能是2*1，这两个特殊情况直接返回就行了。
 *
 * 乘方运算的复杂度为：O(log n)，用动态规划来做会耗时比较多。
 */

class Solution {
public:
	long long  cutRope(int n) {
		if (n == 2) {
			return 1;
		}
		if (n == 3) {
			return 2;
		}
		long long x = n % 3;
		long long y = n / 3;
		if (x == 0) {
			return pow(3, y);   // 3^y 
		}
		else if (x == 1) {
			return 2 * 2 * (long long)pow(3, y - 1);
		}
		else {
			return 2 * (long long)pow(3, y);
		}
	}
};


// 方法： 动态规划
class Solution2 {
public:
	long long  cutRope(int n) {
		// n<=3的情况，m>1必须要分段，例如：3必须分成1、2；1、1、1 ，n=3最大分段乘积是2,
		if (n == 2) return 1;
		if (n == 3) return 2;
		vector<int> dp(n+1);
		/*
	   下面3行是n>=4的情况，跟n<=3不同，4可以分很多段，比如分成1、3，
	   这里的3可以不需要再分了，因为3分段最大才2，不分就是3。记录最大的。
		*/
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		int res = 0;
		for (int i = 4; i <= n; i++) {
			for (int j = 1; j <= i / 2; j++) {  //一般趋于最中间的两个数乘积是最大的，因为正方形面积最大
				res = max(res, dp[j] * dp[i - j]);
			}
			dp[i] = res; 
		}
		return dp[n];
	}
};

void main() {
	Solution S;
	Solution2 S2;
	int n = 13;
	int res = S.cutRope(n);
	int res2 = S2.cutRope(n);
	cout << res << endl;
	cout << res2 << endl; 

}