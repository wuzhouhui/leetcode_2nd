int singleNumber(int *nums, int numsSize)
{
	int	ones, twos, i, common;

	ones = nums[0];
	twos = 0;
	for (i = 1; i < numsSize; i++) {
		twos |= ones & nums[i];
		ones ^= nums[i];
		common = ones & twos;
		ones &= ~common;
		twos &= ~common;
	}
	return(ones);
}

#include <stdio.h>

int main(void)
{
	int	x[] = {1, 2, 3, 3, 2, 2, 3,};
	printf("%d\n", singleNumber(x, sizeof(x) / sizeof(*x)));
	return(0);
}
