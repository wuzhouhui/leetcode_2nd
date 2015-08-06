#ifndef bool
#define bool int
#endif

bool isPalindrome(int x)
{
	if (x < 0)
		return(0);

	long long llx = x;
	long long tmp, rllx;

	if (llx < 0)
		llx = -llx;

	tmp = llx;
	rllx = 0;
	while (tmp) {
		rllx = rllx * 10 + tmp % 10;
		tmp /= 10;
	}

	return(llx == rllx);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
	printf("%d\n", isPalindrome(atoi(argv[1])));
	return(0);
}
