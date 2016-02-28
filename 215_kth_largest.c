static int do_find(int *nums, int numsSize, int k)
{
	int	m, i, t;

	if (numsSize == 1)
		return(nums[0]);
	m = 0;
	for (i = 1; i < numsSize; i++) {
		if (nums[i] <= nums[0])
			continue;
		else {
			m++;
			t = nums[i];
			nums[i] = nums[m];
			nums[m] = t;
		}
	}
	t = nums[0];
	nums[0] = nums[m];
	nums[m] = t;
	if (m == k)
		return(nums[m]);
	else if (m > k)
		return(do_find(nums, m, k));
	else
		return(do_find(nums + m + 1, numsSize - m - 1, k - m - 1));
}

int findKthLargest(int *nums, int numsSize, int k)
{
	return(do_find(nums, numsSize, k - 1));
}

int main(void)
{
	int	x[] = { 5, 2, 4, 1, 3, 6, 0, };
	return(findKthLargest(x, sizeof(x) / sizeof(x[0]), 4));
}
