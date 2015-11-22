
int singleNumber(int *nums, int numsSize)
{
	int	i, t;

	t = nums[0];
	for (i = 1; i < numsSize; i++)
		t ^= nums[i];
	return(t);
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 1, 2, 3, 4, 4, 3, 1 };
	printf("%d\n", singleNumber(x, sizeof(x) / sizeof(x[0])));
	return(0);
}
