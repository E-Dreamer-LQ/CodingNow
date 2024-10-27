// leetcode380-常数时间插入、删除和获取随机元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/insert-delete-getrandom-o1

#include <iostream>
#include <set>
using namespace std;

// 哈希表解决


class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (!(hashset.find(val) == hashset.end())) {
			hashset.insert(val);
			return true;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (hashset.find(val) == hashset.end()) {
			hashset.erase(val);
			return false;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {

	}

private:
	set<int> hashset;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */