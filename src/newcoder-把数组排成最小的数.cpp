// newcoder-把数组排成最小的数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std; 



class Solution {
public:
     string PrintMinNumber(vector<int> numbers) {
         auto cmp = [](const int &a,const int &b){
             string A="";
             string B="";
             A+=to_string(a);
             A+=to_string(b);
             B+=to_string(b);
             B+=to_string(a);
             return A<B;
         };
         string  answer="";
         sort(numbers.begin(),numbers.end(),cmp);
         for(int i=0;i<numbers.size();i++){
             answer+=to_string(numbers[i]);
         }
         return answer;
     }
 };

