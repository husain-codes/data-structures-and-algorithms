#include<stdio.h>

int power(int m , int  n) {
	if (n == 0) return 1;
	return power(m,n-1)*m;
}

//Optimized way: for even and odd
int powerOptimized(int m , int n) {
	if (n == 0) return 1;
	if(n & 1 == 0) return powerOptimized(m*m , n/2);
	else return m * powerOptimized(m*m , (n-1)/2);
}

int main() {
	printf("%d\n",power(2,9));
	printf("%d\n",powerOptimized(9,3));
	return 0;
}