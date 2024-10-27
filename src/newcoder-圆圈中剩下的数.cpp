// newcoder-圆圈中剩下的数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 


//  直观型题解，  可能存在超时
class Solution {
public:
	int findLastNumber(int n, int m) {
		if (n < 1 || m < 1) return -1; 
		vector<int> array(n); 
		int i = -1, step = 0, count = n;
		while (count > 0) {//跳出循环时将最后一个元素也设置为了-1
			i++;           //指向上一个被删除对象的下一个元素
			if (i >= n) i = 0;   //模拟环。
			if (array[i] == -1) continue;  //跳过被删除的对象。
			step++;                     //记录已走过的。
			if (step == m) {             //找到待删除的对象
				array[i] = -1; 
				step = 0; 
				count--;
			}
		}
		return i; //返回跳出循环时的i,即最后一个被设置为-1的元素
	}
};

/*
f[1] = 0;
f[i] = (f[i - 1] + m) % i;  (i > 1)
*/
// 其他题解，约瑟夫环公式
class Solution {
public:
	int LastRemaining_Solution(unsigned int n, unsigned int m)
	{
		if (n == 0)
			return -1;
		if (n == 1)
			return 0;
		else
			return (LastRemaining_Solution(n - 1, m) + m) % n;
	}
};