// gcd算法   最大公约数


int gcd(int x,  int y) {
	if(y == 0) return x;
	int r = x % y;
	return gcd(y, r); 
}