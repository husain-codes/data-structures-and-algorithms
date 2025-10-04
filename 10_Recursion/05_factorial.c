#include<stdio.h>

int Rfact(int);
int Ifact(int);

// T = O(n) , S = O(1)
int Ifact(int n) {
	int fact = 1;
	for(int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}

// T = O(n) , S = O(n)
int Rfact(int n) {
	if (n == 1 || n <= 0) return 1;
	return Rfact(n-1)*n;
	
}

int main() {
	printf("Enter the number : ");
	int n;
	scanf("%d",&n);
	
	printf("Factorial of %d using Iteration is : %d\n",n,Ifact(n));
	printf("Factorial of %d using Recursion is : %d\n",n,Rfact(n));
	return 0;
}