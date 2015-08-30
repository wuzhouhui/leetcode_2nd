static double do_pow(double x, long long n)
{
	double r;

	if (!n)
		return(1.0);
	if (!(n % 2)) {
		r = do_pow(x, n / 2);
		r = r * r;
	} else {
		r = do_pow(x, n - 1);
		r = x * r;
	}
	return(r);
}

double myPow(double x, int n)
{
	long long t;
	double r;

	t = n;
	if (t < 0)
		t = -t;
	r = do_pow(x, t);
	if (n < 0)
		return(1.0 / r);
	else
		return(r);
}

#include <stdio.h>

int main(void)
{
	printf("%f\n", myPow(1.0, -2147483648));
	return(0);
}
