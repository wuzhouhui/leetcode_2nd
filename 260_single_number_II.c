#include <stdlib.h>

int *singleNumber(int *nums, int numsSize, int *returnSize)
{
	int	*res, i, bit, f1, f2, k1, k2;

	k1 = nums[0];
	for (i = 1; i < numsSize; i++)
		k1 ^= nums[i];
	for (i = 0; i < 32; i++)
		if (k1 & (1 << i))
			break;
	bit = 1 << i;
	f1 = f2 = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] & bit) {
			if (f1 == 0) {
				k1 = nums[i];
				f1 = 1;
			} else
				k1 ^= nums[i];
		} else {
			if (f2 == 0) {
				k2 = nums[i];
				f2 = 1;
			} else
				k2 ^= nums[i];
		}
	}
	res = malloc(sizeof(int) + sizeof(int));
	*returnSize = 2;
	res[0] = k1;
	res[1] = k2;
	return(res);
}

int main(void)
{
}
