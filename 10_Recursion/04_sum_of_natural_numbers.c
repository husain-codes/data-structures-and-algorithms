#include<stdio.h>

int RSum(int);
int ISum(int);
int FSum(int);

// T = O(1) , S = O(1)
int FSum(int n) {return (n*(n+1))/2;}

// T = O(n) , S = O(1)
int ISum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += i;
	return sum;
}

// T = O(n) , S = O(n)
int RSum(int n) {
	if(n<= 0) return 0;
	
	return RSum(n-1) + n;
}

int main() {
	printf("Enter the natural number : ");
	int n;
	scanf("%d",&n);
	
	printf("Sum of %d Natural Numbers using Formula is : %d\n",n,FSum(n));
	printf("Sum of %d Natural Numbers using Iteration is : %d\n",n,ISum(n));
	printf("Sum of %d Natural Numbers using Recursion is : %d\n",n,RSum(n));
	return 0;
}