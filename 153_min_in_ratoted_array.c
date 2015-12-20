int findMin(int *nums, int numsSize)
{
	int	left, right, mid;

	if (numsSize == 0)
		return(0);
	if (numsSize == 1)
		return(nums[0]);

	left = 0;
	right = numsSize - 1;
	while (left < right) {
		mid = (left + right) / 2;
		if (nums[left] <= nums[mid] && nums[mid] < nums[right])
			return(nums[left]);
		if (nums[left] >= nums[mid] && nums[mid] > nums[right])
			return(nums[right]);
		if (nums[mid] > nums[right])
			left = mid + 1;
		else
			right = mid;
	}
	return(nums[left]);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 2, 3, 1 };
	printf("%d\n", findMin(x, sizeof(x) / sizeof(x[0])));
	return(0);
}
