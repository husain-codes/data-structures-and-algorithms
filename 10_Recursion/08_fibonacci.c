#include<stdio.h>

// T = O(2^n) : it is calling itself multiple times for same parameters
// Excessive Recursion 
int fib(int n) {
	if(n <= 1) return n;
	return fib(n-2)+fib(n-1);
}

// T = O(n)
int Ifib(int n) {
	int t0 = 0 , t1 = 1 , sum;
	for(int i = 2; i <= n; i++) {
		sum = t0 + t1;
		t0 = t1;
		t1 = sum;
	}
	return sum;
}

// Optimized Recursive - Memoization - storing value
int F[10];

int Rfib(int n) {
	if(n <= 1) {
		F[n] = n;
		return n;
	} else {
		if(F[n-2] == -1) {
			F[n-2] = Rfib(n-2);
		}
		if(F[n-1] == -1) {
			F[n-1] = Rfib(n-1);
		}
		F[n] = F[n-2] + F[n-1];
		return F[n];
	}
}
int main() {
	for(int i = 0; i < 10; i++)
		F[i] = -1;
	
	printf("Fibonacci series for number 7 using simple recursion : %d\n",fib(7));
	printf("Fibonacci series for number 7 using iteration : %d\n",Ifib(7));
	printf("Fibonacci series for number 7 using memoization recursion : %d\n",Rfib(7));
	return 0;
}