// 实际应用： 两数之和， 无重复最长字符串

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 无重复最长子串长度
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	unordered_map<char,int> hashmap;
    	int left = 0,max_len=0;
    	for (int i=0; i < s.size(); i++){
    		if (hashmap.find(s[i]) != hashmap.end()){
    			left = max(left, hashmap[s[i]] +1);// 如果找到了，左边界更新为上一个遍历该元素索引值+1
    		}
    		max_len = max(max_len,i-left+1)
    		hashmap[s[i]] = i;  // 字符对应位置
    	}
    	return max_len;

    }};