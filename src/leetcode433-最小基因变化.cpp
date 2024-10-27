// leetcode433-最小基因变化.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;


// 和单词接龙原理是一样的

class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		queue<string> que;
		que.push(start);
		map<string, int> hashmap{bank.begin(),bank.end() };
		int step = 0;
		string change_str = { 'A', 'G', 'C', 'T' };
		int len = start.size();
		if (!hashmap.count(end)) return 0;
		while (!que.empty()) {
			step++;
			int size = que.size();
			while (size--) {
				string cur = que.front();
				que.pop();
				for (int i = 0; i < len; i++) {
					char c = cur[i];
					for (auto s : change_str) {
						if (s == c) continue;
						cur[i] = s;
						if (cur == end) return step + 1;
						if (!hashmap.count(cur)) continue;
						hashmap.erase(cur);
						que.push(cur);
					}
					cur[i]=c;
				}
			}
		}
		return 0;
	}
};