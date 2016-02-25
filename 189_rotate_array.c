#include <string.h>

void rotate(int *nums, int numsSize, int k)
{
	if (numsSize < 2)
		return;

	int	tmp[numsSize], i;

	k %= numsSize;
	if (k == 0)
		return;
	memcpy(tmp, nums, numsSize * sizeof(nums[0]));
	for (i = 0; i < numsSize; i++)
		nums[(i + k) % numsSize] = tmp[i];
}

#include <stdio.h>

int main(void)
{
	int	x[] = { 1, 2, 3, 4, 5, 6, 7, };
	int	i;

	rotate(x, sizeof(x) / sizeof(x[0]), 3);
	for (i = 0; i < sizeof(x) / sizeof(x[0]); i++)
		printf("%d ", x[i]);
	printf("\n");
	return(0);
}
