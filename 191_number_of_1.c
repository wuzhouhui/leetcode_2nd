#include <stdint.h>

static bit[] = {
	0, 1, 1, 2,
	1, 2, 2, 3,
	1, 2, 2, 3,
	2, 3, 3, 4,
};

int hammingWeight(uint32_t n)
{
	int	i, ret;

	ret = 0;
	for (i = 0; i < 8; i++) {
		ret += bit[n & 0xf];
		n >>= 4;
	}
	return(ret);
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", hammingWeight(11));
	return(0);
}
