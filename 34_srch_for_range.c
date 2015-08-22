#include <stdlib.h>

int *searchRange(int *nums, int numsSize, int target, int *returnSize)
{
	int	l, u, m;
	int	*res;

	res = malloc(sizeof(int) + sizeof(int));
	*returnSize = 2;

	if (!numsSize) {
		res[0] = res[1] = -1;
		return(res);
	}

	l = -1;
	u = numsSize;
	while (l + 1 != u) {
		m = (l + u) / 2;
		if (nums[m] < target)
			l = m;
		else
			u = m;
	}
	if (u == numsSize || nums[u] != target) {
		res[0] = res[1] = -1;
		return(res);
	}
	res[0] = u;

	l = -1;
	u = numsSize;
	while (l + 1 != u) {
		m = (l + u) / 2;
		if (nums[m] > target)
			u = m;
		else
			l = m;
	}
	if (l == -1 || nums[l] != target) {
		res[0] = res[1] = -1;
		return(res);
	}
	res[1] = l;
	return(res);
}

#include <stdio.h>

int main(void)
{
	int *res, n;
	int	x[] = { 5, 7, 7, 8, 8, 10 };

	res = searchRange(x, 6, 8, &n);
	printf("%d %d\n", res[0], res[1]);
	return(0);
}
