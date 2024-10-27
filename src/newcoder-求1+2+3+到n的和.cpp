// newcoder-求1+2+3+到n的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


//  要求： 要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
#include <iostream>

//实现乘法可以用sizeof*** 数组，两行代码就可以
class Solution {
public:
	int Sum_Solution(int n) {
		bool a[n][n + 1];
		return sizeof(a) >> 1;
	}
};

//
class Solution2 {
public:
	int Sum_Solution(int n) {
		int ans = n;
		ans && (ans += Sum_Solution(n - 1)); //&& 就是逻辑与，逻辑与有个短路特点，前面为假，后面不计算
		return ans;
	}
};