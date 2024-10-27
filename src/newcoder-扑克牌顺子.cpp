// newcoder-扑克牌顺子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include <algorithm>
using namespace std; 



class Solution {
public:
	/*顺子满足的条件：max-min<5;
					除0外其他的数字都不能重复
					传入的数组放5个元素*/
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty()) return 0;
		////记录每个元素出现的次数;以numbers中的元素作为下标(最大K,对应13)
		vector<int> count(14);
		count[0] = -5; //d[0]是拿来防止大小王数量影响判断是否有其余对子的
		int len = numbers.size();
		int max = -1;
		int min = 14;

		for (int i = 0; i < len; ++i)
		{
			count[numbers[i]]++;
			if (numbers[i] == 0) continue;

			if (count[numbers[i]] > 1) return false;

			if (numbers[i] > max) max = numbers[i];

			if (numbers[i] < min) min = numbers[i];

		}//end for

		if (max - min < 5) return true;

		return false;

	}//end IsContinuous()
};


class Solution2 {

public: 
	bool isContinuous(vector<int> numbers) {
		int numofzero = 0; 
		int numofinterval = 0; 
		int length = numbers.size();
		if (length == 0) {
			return false; 
		}
		sort(numbers.begin(), numbers.end()); 
		for (int i = 0; i < length - 1; i++) {
			// 计算癞子数量
			if (numbers[i] == 0) {
				numofzero++; 
				continue; 
			}
			// 对子，直接返回
			if (numbers[i] == numbers[i + 1]) {
				return false; 
			}
			numofinterval += numbers[i + 1] - numbers[i] - 1; 

		}
		if (numofzero >= numofinterval) {
			return true; 
		}
		return false; 
	}
};