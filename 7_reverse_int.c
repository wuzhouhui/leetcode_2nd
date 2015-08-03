#include <limits.h>
#include <stdio.h>

int reverse(int x)
{
	long long llx;
	int	neg, i, l;
	char	c;
	static char str[32];

	llx = (long long)x;
	if (llx < 0) {
		llx = -llx;
		neg = 1;
	} else {
		neg = 0;
	}
	l = sprintf(str, "%lld", llx);
	for (i = 0; i < l / 2; i++) {
		c = str[l - i - 1];
		str[l - i - 1] = str[i];
		str[i] = c;
	}
	llx = 0;
	for (i = 0; i < l; i++)
		llx = llx * 10 + str[i] - '0';
	if (neg)
		llx = -llx;
	if (llx < INT_MIN || llx > INT_MAX)
		return(0);
	return((int)llx);
}

int main(int argc, char *argv[])
{
	printf("%d\n", reverse(atoll(argv[1])));
	return(0);
}
