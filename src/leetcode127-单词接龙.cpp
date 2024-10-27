// leetcode127-单词接龙.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;


class Solution {
public:
	int laddrerLength(string beginWord, string endWord, vector<string>& wordList) {
		map<string, int> hashmap;
		for (auto str : wordList) {
			hashmap[str]++;
		}
		if (hashmap[endWord] == 0) {
			return 0;
		}
		queue<string> que;
		que.push(beginWord);
		int step=0;
		int len = beginWord.size();
		while (!que.empty()) {
			step++; //BFS，遍历完一层step++
			int size = que.size();
			while (size--) {
				string cur = que.front();
				que.pop();
				for (int i = 0; i < len; i++) {
					char c = cur[i]; // 缓存，下面要改变
					for (int j = 'a'; j <= 'z'; j++) {
						if (j == c) continue; // 跳过本身
						cur[i] = j;
						// 如果已经转换到了
						if (cur == endWord)  return step + 1;
						if (!hashmap.count(cur)) continue;
						hashmap.erase(cur);// 访问完就删除，转换的过程中访问过的
						que.push(cur); // 将符合条件的单词节点加入队列
					}
					cur[i] = c;// 可能一个单词可以转换多个单词 ？？，还原原来改变的单词
				}
			}
		}
		return 0; 
	}
};

