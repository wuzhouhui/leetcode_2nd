#include <stdlib.h>
#include <stdint.h>

int *grayCode(int n, int *returnSize)
{
	int	*res;
	uint64_t i, j;

	res = malloc(sizeof(res[0]) * (1 << n));
	j = (uint64_t)1 << n;
	for (i = 0; i < j; i++)
		res[i] = (i >> 1) ^ i;
	*returnSize = 1 << n;
	return(res);
}

int main(void)
{
}
