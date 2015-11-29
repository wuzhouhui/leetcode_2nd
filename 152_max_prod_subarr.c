static inline int max(int a, int b)
{
	return(a > b ? a : b);
}

static inline int min(int a, int b)
{
	return(a < b ? a : b);
}

int maxProduct(int *nums, int numsSize)
{
	if (!numsSize)
		return(0);

	int	cur_max, cur_min, i, glo_max, t;

	cur_max = cur_min = glo_max = nums[0];
	for (i = 1; i < numsSize; i++) {
		t = cur_max;
		cur_max = max(nums[i], max(cur_max * nums[i], cur_min *
					nums[i]));
		cur_min = min(nums[i], min(t * nums[i], cur_min * nums[i]));
		glo_max = max(cur_max, glo_max);
	}

	return(glo_max);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { -2, 3, -4 };
	printf("%d\n", maxProduct(x, sizeof(x) / sizeof(*x)));
	return(0);
}
