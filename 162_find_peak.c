int findPeakElement(int *nums, int numsSize)
{
	int	left, right, mid;

	if (numsSize < 2)
		return(0);

	left = 0;
	right = numsSize - 1;
	while (left < right) {
		mid = (left + right) / 2;
		if (mid == left)
			return(nums[left] > nums[right] ? left : right);
		if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid +1])
			left = mid;
		else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1])
			right = mid;
		else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
			return(mid);
		else
			right = mid;
	}
	return(0);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 1, 2, 3, 1, };
	printf("%d\n", findPeakElement(x, sizeof(x) / sizeof(x[0])));
	return(0);
}
