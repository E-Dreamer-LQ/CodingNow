// leetcode319-灯泡开关.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/bulb-switcher

#include <iostream>
using namespace std;




/*
先扔结论：第i个灯泡从最初状态到最后操作完毕，被操作的次数等价于i的约数个数
如果灯最终是亮着的，则说明i有奇数个约数。
问题转化为求那几个数有奇数个约数：
一个数如果有奇数个约数，则这个数肯定是个完全平方数
1 - n中是完全平方数的数的个数为：floor(sqrt(n))
*/
class Solution {
public:
	int bulbSwitch(int n) {
		// 因为n个灯泡翻转n轮，我们只要看看到n位置，一共有多少个完全平方数即可。
		return sqrt(n);
	}
};



// 牛顿法求平方数
class Solution2 {
public:
	int bulbSwitch(int n) {
		if (n < 1) return 0;
		long r = n;
		while (r * r > n) {
			r = (r + n / r) / 2; 
		}
		return (int)r;
	}
};

/*
经过(xi, f(xi))这个点的切线方程为f(x) = f(xi) + f’(xi)(x - xi)，其中f'(x)为f(x)的导数，本题中为2x。
令切线方程等于0，即可求出xi+1=xi - f(xi) / f'(xi)。
继续化简，xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2。

*/


