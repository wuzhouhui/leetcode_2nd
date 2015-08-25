int firstMissingPositive(int *nums, int numsSize)
{
	int	i, t;

	i = 0;
	while (i < numsSize) {
		if (nums[i] <= 0 || nums[i] > numsSize || nums[i] == i + 1
				|| nums[i] == nums[nums[i] - 1])
			i++;
		else {
			t = nums[nums[i] - 1];
			nums[nums[i] - 1] = nums[i];
			nums[i] = t;
		}
	}

	for (i = 0; i < numsSize; i++)
		if (nums[i] != i + 1)
			return(i + 1);
	return(numsSize + 1);
}

#include <stdio.h>

int main(void)
{
	int nums[] = { 1, 1};
	printf("%d\n", firstMissingPositive(nums, 2));
	return(0);
}
