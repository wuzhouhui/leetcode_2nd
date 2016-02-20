int findMin(int *nums, int numsSize)
{
	int	left, right, mid;

	if (!numsSize)
		return(0);
	if (numsSize == 1)
		return(nums[0]);

	left = 0;
	right = numsSize - 1;
	while (left < right) {
		mid = (left + right) / 2;
		if (mid == left)
			return(nums[left] < nums[right] ?
					nums[left] : nums[right]);
		if (nums[left] < nums[right])
			return(nums[left]);
		else if (nums[left] > nums[right]) {
			if (nums[mid] > nums[left])
				left = mid + 1;
			else if (nums[mid] < nums[left])
				right = mid;
			else
				left++;
		} else {
			if (nums[mid] == nums[left])
				left++;
			else if (nums[mid] < nums[left])
				right = mid;
			else
				left = mid + 1;
		}
	}
	return(nums[left]);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 1, 2, 1, };
	printf("%d\n", findMin(x, sizeof(x) / sizeof(x[0])));
	return(0);
}
