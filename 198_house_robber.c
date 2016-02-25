int rob(int *nums, int numsSize)
{
	if (!numsSize)
		return(0);
	if (numsSize == 1)
		return(nums[0]);

	int	sum[numsSize];
	int	t, i;

	sum[0] = nums[0];
	sum[1] = nums[0] > nums[1] ? nums[0] : nums[1];
	for (i = 2; i < numsSize; i++) {
		t = nums[i] + sum[i - 2];
		sum[i] = t > sum[i - 1] ? t : sum[i - 1];
	}
	return(sum[numsSize - 1]);
}

int main(void)
{
}
