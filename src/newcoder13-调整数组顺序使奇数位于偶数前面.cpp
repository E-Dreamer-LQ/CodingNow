// newcoder13-调整数组顺序使奇数位于偶数前面.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

//两个思路吧，第一个思路：类似冒泡算法，前偶后奇数就交换：
class Solution {
public:
	vector<int> reOrderArray(vector<int>& array) {  // 原题目为 void 


		for (int i = 0; i < array.size(); i++)
		{
			for (int j = array.size() - 1; j > i; j--)   
			{
				if (array[j] % 2 == 1 && array[j - 1] % 2 == 0) //前偶后奇交换
				{
					swap(array[j], array[j - 1]);
				}
			}
		}
		return array; 
	}
};

class Solution2 {
public:
	vector<int>  reOrderArray(vector<int>& array) {
		//相对位置不变，稳定性
		//插入排序的思想
		int m = array.size();
		int k = 0;//记录已经摆好位置的奇数的个数
		for (int i = 0; i < m; i++) {
			if (array[i] % 2 == 1) {
				int j = i;
				while (j > k) {//j >= k+1
					swap(array[j], array[j - 1]);
					j--;
				}
				k++;
			}
		}
		return array;
	}
};



void main() {
	vector<int> array{1,2,3,4,5,6,7,8};
	Solution S;
	Solution S2; 
	vector<int> res = S.reOrderArray(array);
	vector<int> res2 = S2.reOrderArray(array);
	for (auto num1:res) {
		cout << num1;
	}
	cout << endl;
	for (auto num2 : res2) {
		cout << num2;
	}
	cout << endl; 
	

}