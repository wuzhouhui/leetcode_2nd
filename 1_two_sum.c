#include <stdlib.h>

struct valind {
	int	val;
	int	ind;
};

static int intcmp(const void *a, const void *b)
{
	struct valind *x = (struct valind *)a;
	struct valind *y = (struct valind *)b;
	return(x->val - y->val);
}

int *twoSum(int *nums, int numsSize, int target)
{
	int	left, right, sum;
	int	*res;
	struct valind x[numsSize];

	for (left = 0; left < numsSize; left++) {
		x[left].val = nums[left];
		x[left].ind = left;
	}
	qsort(x, numsSize, sizeof(x[0]), intcmp);
	left = 0;
	right = numsSize - 1;
	while (left < right) {
		sum = x[left].val + x[right].val;
		if (sum == target)
			break;
		else if (sum < target)
			left++;
		else
			right--;
	}
	res = malloc(sizeof(int) + sizeof(int));
	if (x[left].ind < x[right].ind) {
		res[0] = x[left].ind + 1;
		res[1] = x[right].ind + 1;
	} else {
		res[0] = x[right].ind + 1;
		res[1] = x[left].ind + 1;
	}
	return(res);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 3, 2, 4 };
	int	*res = twoSum(x, sizeof(x) / sizeof(x[0]), 6);
	printf("%d %d\n", res[0], res[1]);
	return(0);
}
