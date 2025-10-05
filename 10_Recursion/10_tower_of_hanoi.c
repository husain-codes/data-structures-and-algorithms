#include<stdio.h>

void TOH(int n , char A , char B , char C) {
	if (n > 0){ 
		TOH(n-1,A,C,B);
		printf("Moving disk from %c to %c\n",A,C);
		TOH(n-1,B,A,C);
	}
}

int main() {
	printf("Enter number of disk for tower of hanoi : ");
	int n;
	scanf("%d",&n);
	
	TOH(n,'A','B','C');
	return 0;
}