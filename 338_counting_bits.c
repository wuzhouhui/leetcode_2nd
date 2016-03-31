#include <stdlib.h>

static char bit[] = {
	0, 1, 1, 2,
	1, 2, 2, 3,
	1, 2, 2, 3,
	2, 3, 3, 4,
};

int *countBits(int num, int *returnSize)
{
	int	*res;
	int	i, t;

	*returnSize = num + 1;
	res = calloc(*returnSize, sizeof(res[0]));
	for (i = 0; i <= num; i++) {
		t = i;
		res[i] += bit[t & 0xf]; t >>= 4;
		res[i] += bit[t & 0xf]; t >>= 4;
		res[i] += bit[t & 0xf]; t >>= 4;
		res[i] += bit[t & 0xf]; t >>= 4;
		res[i] += bit[t & 0xf]; t >>= 4;
		res[i] += bit[t & 0xf]; t >>= 4;
		res[i] += bit[t & 0xf]; t >>= 4;
		res[i] += bit[t & 0xf]; t >>= 4;
	}
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	*res, i, n;
	res = countBits(5, &n);
	for (i = 0; i < n; i++)
		printf("%d\n", res[i]);
	return(0);
}
