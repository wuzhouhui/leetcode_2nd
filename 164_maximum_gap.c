/*
 * Too slow, but accepted.
 */

#include <stdlib.h>

static int intcmp(const void *a, const void *b)
{
	return(*(int *)a - *(int *)b);
}

int maximumGap(int *nums, int numsSize)
{
	int	i, t, max;

	if (numsSize < 2)
		return(0);
	qsort(nums, numsSize, sizeof(nums[0]), intcmp);
	max = 0;
	for (i = 1; i < numsSize; i++) {
		if (nums[i - 1] < nums[i])
			t = nums[i] - nums[i - 1];
		else
			t = nums[i - 1] - nums[i];
		if (t > max)
			max =t ;
	}
	return(max);
}

int main(void)
{
}
