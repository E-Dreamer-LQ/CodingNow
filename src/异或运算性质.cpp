﻿// 异或运算性质.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>


// 异或运算的性质:简单理解就是不进位加法，如1+1=0，,0+0=0,1+0=1

//  1. 如果 a^ b = c 成立，那么a ^ c = b 与 b ^ c = a 均成立。
// 2. 

1、交换律

2、结合律（即(a ^ b) ^ c == a ^ (b ^ c)）

3、对于任何数x，都有x ^ x = 0，x ^ 0 = x

4、自反性 A XOR B XOR B = A xor 0 = A