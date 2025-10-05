#include<stdio.h>

double Taylor(double x , double n) {
	static double p = 1, f = 1;
	double r;
	if (n == 0) return 1;
	else {
		r = Taylor(x,n-1);
		p = p * x;
		f = f * n;
		return r + p/f;
	}
}

double HornerTaylor(double x , double n) {
	static double s = 1;
	if (n == 0) return s;
	s = 1 + (x/n) * s;
	return HornerTaylor(x,n-1);
}

double IHornerTaylor(double x , double n) {
	double s = 1;
	for(int i = n; i > 0; i--)
		s = 1 + (x/i) * s;
	return s;
}
int main() {
	printf("Taylor using simple recursion %f\n",Taylor(1,100));
	printf("Taylor using Horner recursion %f\n",HornerTaylor(1,100));
	printf("Taylor using Iterative Horner recursion %f\n",IHornerTaylor(1,100));
	return 0;
}