// leetcode526-优美的排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/beautiful-arrangement/

#include <iostream>
#include <vector>
using namespace std;

/*
1. 第 i 位的数字能被 i 整除
2. i 能被第 i 位上的数字整除
*/

/*
使用函数 calculate，它将从 1 到 N 所有还没有被使用过的数字放到当前位置 pos，
并检查是否满足可除性。如果 ii 放到当前位置 pos 是满足要求的，我们就把 ii 
放在当前位置 pos 并继续考虑下一个位置 pos + 1，
否则我们需要换一个数字放在当前位置*/

class Solution {
public:
	int count = 0; 
	int countArrangement(int N) {
		vector<bool> visited(N,false);
		calculate(N, 1, visited);
		return count; 
	}
	void calculate(int N, int pos, vector<bool> visited) {
		if (pos > N) {
			count++;  // return 1 
		} 
		for (int i = 1; i <= N; i++) {
			if (!visited[i] && (pos % i == 0 || i % pos == 0))
			{
				visited[i] = true;  // 符合可除性
				calculate(N, pos + 1, visited);
				visited[i] = false;  // 已经访问
			}
		}
	}
};