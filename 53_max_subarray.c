int maxSubArray(int *nums, int numsSize)
{
	int sum[numsSize];
	int cur, t, i;

	if (!numsSize)
		return(0);

	for (i = 0; i < numsSize; i++) {
		if (i == 0) {
			sum[0] = nums[0];
			cur = nums[0];
			continue;
		}
		t = cur + nums[i];
		cur = t > nums[i] ? t : nums[i];
		sum[i] = sum[i - 1] > cur ? sum[i - 1] : cur;
	}
	return(sum[numsSize - 1]);
}

#include <stdio.h>

int main(void)
{
	int	x[] = {-1, 1, -3, 4, -1, 2, 1, -5, 4};
	printf("%d\n", maxSubArray(x, 9));
	return(0);
}
