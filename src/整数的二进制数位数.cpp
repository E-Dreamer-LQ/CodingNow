

class Solution {public:
    int count(int num) {
        int sz = log(num) / log(2) + 1;
        return sz; 
    }
};