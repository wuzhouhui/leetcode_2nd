int trailingZeroes(int n)
{
	int	c;

	c = 0;
	while (n) {
		n /= 5;
		c += n;
	}
	return(c);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("%d\n", trailingZeroes(atoi(argv[1])));
	return(0);
}
