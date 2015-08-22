int search(int *nums, int numsSize, int target)
{
	if (!numsSize)
		return(-1);
	if (numsSize == 1)
		return(nums[0] == target ? 0 : -1);

	int	left, right, m;

	left = 0;
	right = numsSize - 1;
	while (left <= right) {
		m = (left + right) / 2;
		if (nums[m] == target)
			return(m);

		if (nums[left] <= nums[m] && nums[m] <= nums[right]) {
			if (target < nums[m])
				right = m - 1;
			else
				left = m + 1;
			continue;
		}

		if (nums[m] >= nums[left]) {
			if (target > nums[m])
				left = m + 1;
			else if (target < nums[m] && target >= nums[left])
				right = m - 1;
			else
				left = m + 1;
			continue;
		}

		if (target < nums[m])
			right = m - 1;
		else {
			if (target > nums[right])
				right = m - 1;
			else
				left = m + 1;
		}
	}
	return(-1);
}

#include <stdio.h>

int main(void)
{
	int x[] = { 4, 6, 5, 7, 0, 1, 2 };
	printf("%d\n", search(x, 7, 1));
	return(0);
}
