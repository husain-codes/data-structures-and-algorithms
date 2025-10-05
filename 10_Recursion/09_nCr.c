#include<stdio.h>

int fact(int n) {
	if(n == 0 || n == 1) return 1;
	return fact(n-1)*n;
}

int nCr(int n , int r) {
	return (fact(n)/(fact(r) * fact(n-r)));
}

int NCR(int n , int r) {
	if (r == 0 || r == n) return 1;
	return NCR(n-1,r-1) + NCR(n-1,r);
}

int main() {
	printf("value of 5C2 using simple recursive fact method is : %d\n", nCr(5,2));
	printf("value of 5C2 using recursion : %d\n", NCR(5,2));
	return 0;
}