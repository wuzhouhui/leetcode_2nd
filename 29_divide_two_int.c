#include <limits.h>

int divide(int dividend, int divisor)
{
	long long lx, ly, res;
	long long int	n;


	lx = (long long)dividend;
	ly = (long long)divisor;
	if (lx < 0)
		lx = -lx;
	if (ly < 0)
		ly = -ly;

	if (!ly)
		return(dividend < 0 ? INT_MIN : INT_MAX);
	if (!lx)
		return(0);
	if (ly == 1) {
		if (divisor == 1)
			return(dividend);

		/* divisor == -1 */
		if (dividend >= 0)
			return(-dividend);
		else {
			if (dividend == INT_MIN)
				return(INT_MAX);
			else
				return(-dividend);
		}
	}

	res = 0;
	while (lx >= ly) {
		n = 0;
		while (ly * ((long long)1 << n) <= lx)
			n++;
		n--;
		res += (long long)1 << n;
		lx -= ly * ((long long)1 << n);
	}

	if ((long long)dividend * (long long)divisor < 0) {
		res = -res;
		return(res < INT_MIN ? INT_MIN : (int)res);
	}
	return(res > INT_MAX ? INT_MAX : (int)res);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	printf("%d\n", divide(n1, n2));
	return(0);
}
