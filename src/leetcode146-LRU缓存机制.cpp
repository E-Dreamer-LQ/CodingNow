// leetcode146-LRU缓存机制.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/lru-cache

#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;


class LRUCache {
public:
	LRUCache(int capacity) : capacity_(capacity) {}
	int get(int key) {
		if (hashmap.count(key) == 0)
			return -1;
		else {
			int val = hashmap[key]->second;
			lis.erase(hashmap[key]);
			lis.push_front(make_pair(key, val));
			hashmap[key] = lis.begin(); // 新放入的元素地址成为链表的头结点
			return val;
		}
	}
	void put(int key, int value) {
		if (hashmap.count(key) != 0) {
			lis.erase(hashmap[key]);
		}
		else if (lis.size() >= capacity_) {
			hashmap.erase(lis.back().first);//每访问一次键值，就把这个键值插入到链表（页表）头,链表尾为最近最少访问的key
			lis.pop_back();   // 删除最近最久未访问的数据
		}
		lis.push_front(make_pair(key, value));
		hashmap[key] = lis.begin();  // 迭代器存入哈希表   
	}
private:
	int capacity_;
	list<pair<int, int>> lis;
	//假设删除秘钥为key的节点，不用遍历在链表中查询了，可以O(1)的获取将要删除的节点的迭代器！即hashmap[key].,="">,>
	unordered_map<int, list<pair<int, int>>::iterator> hashmap;
};


